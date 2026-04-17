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
#include <thread>

int main() {
  SharedLogger logger("application.log");

  std::thread t1([&]() { logger.log("Thread 1 started"); });

  std::thread t2([&]() { logger.log("Thread 2 started"); });

  t1.join();
  t2.join();

  logger.log("Application shutting down");
}
