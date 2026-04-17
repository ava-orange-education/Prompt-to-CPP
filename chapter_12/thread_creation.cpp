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
// thread_creation.cpp
// This code demonstrates the creation and management of a thread in C++17.
// A separate thread is spawned to simulate sampling data from a sensor
// while the main thread continues to perform other tasks.
#include <chrono>
#include <iostream>
#include <thread>

void sample_sensor()
{
    for (int i = 0; i < 5; ++i)
    {
        std::cout << "Sample " << i << ": 23.4 C\n";
        std::this_thread::sleep_for(std::chrono::milliseconds(800));
    }
}

int main()
{
    std::thread sensor_thread(sample_sensor);

    std::cout << "Main: Processing control loop...\n";
    std::this_thread::sleep_for(std::chrono::milliseconds(2000));

    sensor_thread.join();
    return 0;
}