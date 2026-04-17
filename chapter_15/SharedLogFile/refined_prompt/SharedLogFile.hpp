/*
 * File: SharedLogFile.hpp
 * Purpose: Thread-safe shared log file manager with RAII, move support, and
 * buffered writes (C++20)
 */

#ifndef SHARED_LOG_FILE_HPP
#define SHARED_LOG_FILE_HPP

#include <chrono>
#include <condition_variable>
#include <cstddef>
#include <ctime>
#include <fstream>
#include <iomanip>
#include <mutex>
#include <optional>
#include <ostream>
#include <sstream>
#include <stdexcept>
#include <string>
#include <string_view>
#include <utility>
#include <vector>

class SharedLogFile {
public:
  enum class FlushPolicy {
    Manual,         // Flush only when flush() is called
    FlushEachWrite, // Flush on every write (slower, but robust)
    FlushOnNewline  // Flush when message ends with '\n'
  };

  struct Options {
    std::size_t bufferedBytes =
        64 * 1024; // 0 => unbuffered (std::endl/flush policy still applies)
    FlushPolicy flushPolicy = FlushPolicy::Manual;
    bool addTimestamp = true;
  };

public:
  explicit SharedLogFile(std::string filePath, Options options = {})
      : m_filePath(std::move(filePath)), m_options(options), m_logFile(),
        m_mutex(), m_buffer(), m_userBuffer() {
    openOrThrow();

    // Optional: configure std::ofstream buffering.
    // This uses a user-managed buffer for the streambuf; it is safe as long as
    // it outlives m_logFile. Note: buffering is still subject to OS buffering
    // and may not flush until policy/flush().
    if (m_options.bufferedBytes > 0) {
      m_userBuffer.resize(m_options.bufferedBytes);
      m_logFile.rdbuf()->pubsetbuf(
          m_userBuffer.data(),
          static_cast<std::streamsize>(m_userBuffer.size()));
    }

    // Reserve internal staging buffer for batching writes.
    // This reduces lock contention if callers log frequently.
    if (m_options.bufferedBytes > 0) {
      m_buffer.reserve(m_options.bufferedBytes);
    }
  }

  ~SharedLogFile() noexcept {
    // Destructors must not throw.
    // Best-effort flush of staged data.
    try {
      flush();
    } catch (...) {
      // Swallow exceptions.
    }
  }

  // Non-copyable: owning a file handle and buffer.
  SharedLogFile(const SharedLogFile &) = delete;
  SharedLogFile &operator=(const SharedLogFile &) = delete;

  // Movable: transfer ownership safely.
  SharedLogFile(SharedLogFile &&other) noexcept { moveFrom(std::move(other)); }

  SharedLogFile &operator=(SharedLogFile &&other) noexcept {
    if (this != &other) {
      // Flush our own pending data first (best-effort).
      try {
        flush();
      } catch (...) {
      }

      moveFrom(std::move(other));
    }
    return *this;
  }

  void write(std::string_view message) {
    // Prepare the final line outside the critical section where possible.
    // Timestamp generation is relatively expensive; avoid holding the mutex.
    std::string line;
    line.reserve(message.size() + 64);

    if (m_options.addTimestamp) {
      line.append("[");
      line.append(timestampNow());
      line.append("] ");
    }

    line.append(message.data(), message.size());

    // Now lock and append/write.
    std::scoped_lock lock(m_mutex);

    ensureOpenOrThrow();

    if (m_options.bufferedBytes == 0) {
      // Direct-to-stream path.
      m_logFile.write(line.data(), static_cast<std::streamsize>(line.size()));
      applyFlushPolicy(line);
      return;
    }

    // Buffered staging: accumulate, flush when threshold exceeded.
    m_buffer.insert(m_buffer.end(), line.begin(), line.end());

    if (m_buffer.size() >= m_options.bufferedBytes) {
      flushLocked();
    } else {
      applyFlushPolicyBuffered(line);
    }
  }

  void writeln(std::string_view message) {
    // Avoid two locks by building with newline first.
    std::string tmp;
    tmp.reserve(message.size() + 1);
    tmp.append(message.data(), message.size());
    tmp.push_back('\n');
    write(tmp);
  }

  void flush() {
    std::scoped_lock lock(m_mutex);

    if (!m_logFile.is_open()) {
      return; // no-op if moved-from or never opened
    }

    if (m_options.bufferedBytes > 0 && !m_buffer.empty()) {
      flushLocked();
    }

    m_logFile.flush();
    // If flush fails, iostreams set badbit/failbit; we validate by checking
    // state:
    if (!m_logFile) {
      throw std::runtime_error("Log file flush failed: " + m_filePath);
    }
  }

  bool isOpen() const noexcept {
    std::scoped_lock lock(m_mutex);
    return m_logFile.is_open();
  }

  const std::string &path() const noexcept { return m_filePath; }

private:
  void openOrThrow() {
    m_logFile.open(m_filePath,
                   std::ios::out | std::ios::app | std::ios::binary);

    if (!m_logFile.is_open()) {
      throw std::runtime_error("Failed to open log file: " + m_filePath);
    }

    // Ensure stream is in a good state right after open.
    if (!m_logFile) {
      throw std::runtime_error(
          "Log file stream is in a bad state after open: " + m_filePath);
    }
  }

  void ensureOpenOrThrow() {
    // Caller must hold lock.
    if (!m_logFile.is_open()) {
      throw std::runtime_error("Log file is not open (moved-from or closed): " +
                               m_filePath);
    }
  }

  void flushLocked() {
    // Caller must hold lock.
    if (m_buffer.empty()) {
      return;
    }

    m_logFile.write(m_buffer.data(),
                    static_cast<std::streamsize>(m_buffer.size()));
    m_buffer.clear();

    if (!m_logFile) {
      throw std::runtime_error("Log file write failed: " + m_filePath);
    }
  }

  void applyFlushPolicy(const std::string &line) {
    // Caller must hold lock.
    switch (m_options.flushPolicy) {
    case FlushPolicy::Manual:
      break;

    case FlushPolicy::FlushEachWrite:
      m_logFile.flush();
      break;

    case FlushPolicy::FlushOnNewline:
      if (!line.empty() && line.back() == '\n') {
        m_logFile.flush();
      }
      break;
    }

    if (!m_logFile) {
      throw std::runtime_error("Log file stream error after write/flush: " +
                               m_filePath);
    }
  }

  void applyFlushPolicyBuffered(const std::string &line) {
    // Caller must hold lock.
    switch (m_options.flushPolicy) {
    case FlushPolicy::Manual:
      break;

    case FlushPolicy::FlushEachWrite:
      flushLocked();
      m_logFile.flush();
      break;

    case FlushPolicy::FlushOnNewline:
      if (!line.empty() && line.back() == '\n') {
        flushLocked();
        m_logFile.flush();
      }
      break;
    }

    if (!m_logFile) {
      throw std::runtime_error(
          "Log file stream error after buffered write/flush: " + m_filePath);
    }
  }

  static std::string timestampNow() {
    using clock = std::chrono::system_clock;

    const auto now = clock::now();
    const auto timeT = clock::to_time_t(now);
    const auto millis = std::chrono::duration_cast<std::chrono::milliseconds>(
                            now.time_since_epoch()) %
                        1000;

    std::tm tm{};

#if defined(_WIN32)
    localtime_s(&tm, &timeT);
#else
    localtime_r(&timeT, &tm);
#endif

    std::ostringstream oss;
    oss << std::put_time(&tm, "%Y-%m-%d %H:%M:%S") << "." << std::setw(3)
        << std::setfill('0') << millis.count();

    return oss.str();
  }

  void moveFrom(SharedLogFile &&other) noexcept {
    // Lock both mutexes without deadlock.
    // It is OK if 'other' is moved-from later; scoped_lock handles ordering.
    std::scoped_lock lock(m_mutex, other.m_mutex);

    m_filePath = std::move(other.m_filePath);
    m_options = other.m_options;
    m_logFile = std::move(other.m_logFile);
    m_buffer = std::move(other.m_buffer);
    m_userBuffer = std::move(other.m_userBuffer);

    // Leave other in a valid, inert state.
    other.m_filePath.clear();
    other.m_buffer.clear();
    other.m_userBuffer.clear();
  }

private:
  std::string m_filePath;
  Options m_options;

  std::ofstream m_logFile;
  mutable std::mutex m_mutex;

  // Internal staging buffer (batched writes).
  std::vector<char> m_buffer;

  // Optional user-provided buffer for ofstream's streambuf.
  std::vector<char> m_userBuffer;
};

#endif // SHARED_LOG_FILE_HPP
