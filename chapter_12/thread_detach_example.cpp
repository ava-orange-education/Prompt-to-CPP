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
// thread_detach_example.cpp
// Demonstrates detaching a background thread for system monitoring
#include <chrono>
#include <iostream>
#include <thread>

void monitor_system()
{
    auto start = std::chrono::steady_clock::now();
    while ((std::chrono::steady_clock::now() - start) < std::chrono::seconds(8))
    {
        std::cout << "[Monitor] Checking system health...\n";
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }
    std::cout << "[Monitor] Timed out and shutting down cleanly.\n";
}

int main()
{
    std::cout << "Main: Starting server...\n";
    
    {
        // Launch and detach background monitoring thread
        std::thread monitor_thread(monitor_system);
        monitor_thread.detach();
    }

    // Simulate main server activity (shorter than monitor timeout)
    for (int i = 0; i < 5; ++i)
    {
        std::cout << "Main: Handling client request " << i << '\n';
        std::this_thread::sleep_for(std::chrono::milliseconds(800));
    }

    std::cout << "Main: Server shutting down.\n";
    return 0;
}