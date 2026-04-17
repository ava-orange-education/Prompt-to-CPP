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
#include "SharedLogFile.hpp"
#include <thread>

int main() {
  SharedLogFile::Options opts;
  opts.bufferedBytes = 128 * 1024;
  opts.flushPolicy = SharedLogFile::FlushPolicy::FlushOnNewline;

  SharedLogFile logger("app.log", opts);

  std::thread t1([&] { logger.writeln("Thread 1: started"); });
  std::thread t2([&] { logger.writeln("Thread 2: started"); });

  t1.join();
  t2.join();

  logger.writeln("Main: shutting down");
  logger.flush();
}
