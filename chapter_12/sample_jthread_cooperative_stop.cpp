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
// sample_jthread_cooperative_stop.cpp
// This code demonstrates the use of std::jthread with cooperative stopping.
// The worker function checks for stop requests and exits gracefully when a stop is requested.
#include <chrono>
#include <iostream>
#include <thread>

void worker(std::stop_token stop)
{
    int count = 100;
    while (count-- && !stop.stop_requested())
    {
        std::cout << "Hello there\n";
        std::this_thread::sleep_for(std::chrono::milliseconds(2));
    }
}

int main()
{
    std::jthread mythread{ worker };

    std::this_thread::sleep_for(std::chrono::milliseconds(100));

    return 0;
}
