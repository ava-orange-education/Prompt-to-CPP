/*
 * File: SharedLogger.cpp
 * Purpose: Implementation of SharedLogger
 */

#include "SharedLogger_weak_prompt.hpp"

#include <chrono>
#include <iomanip>
#include <sstream>
#include <stdexcept>

SharedLogger::SharedLogger(const std::string &filePath) {
  m_logFile.open(filePath, std::ios::out | std::ios::app);

  if (!m_logFile.is_open()) {
    throw std::runtime_error("Failed to open log file: " + filePath);
  }
}

SharedLogger::~SharedLogger() {
  if (m_logFile.is_open()) {
    m_logFile.flush();
    m_logFile.close();
  }
}

void SharedLogger::log(const std::string &message) {
  std::lock_guard<std::mutex> lock(m_mutex);

  m_logFile << "[" << getTimestamp() << "] " << message << std::endl;
}

std::string SharedLogger::getTimestamp() const {
  using clock = std::chrono::system_clock;
  const auto now = clock::now();
  const auto time = clock::to_time_t(now);

  std::tm tm{};

#if defined(_WIN32)
  localtime_s(&tm, &time);
#else
  localtime_r(&time, &tm);
#endif

  std::ostringstream oss;
  oss << std::put_time(&tm, "%Y-%m-%d %H:%M:%S");

  return oss.str();
}
