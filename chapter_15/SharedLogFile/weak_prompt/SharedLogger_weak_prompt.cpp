/*
 * Copyright (C) 2026
 * Author: Vivek Bhadra
 * 
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program. If not, see <https://www.gnu.org/licenses/>.
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
