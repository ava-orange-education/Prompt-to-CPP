// SharedredLogger_weak_prompt.hpp
// This is the header file for a thread-safe shared log file manager in C++14.
#ifndef SHARED_LOGGER_HPP
#define SHARED_LOGGER_HPP

#include <fstream>
#include <mutex>
#include <string>

class SharedLogger {
public:
  explicit SharedLogger(const std::string &filePath);
  ~SharedLogger();

  // Non-copyable
  SharedLogger(const SharedLogger &) = delete;
  SharedLogger &operator=(const SharedLogger &) = delete;

  // Logging interface
  void log(const std::string &message);

private:
  std::ofstream m_logFile;
  std::mutex m_mutex;

  std::string getTimestamp() const;
};

#endif // SHARED_LOGGER_HPP
