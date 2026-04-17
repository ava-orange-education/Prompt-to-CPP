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
// atomic_operations_example.cpp
// This code demonstrates the use of std::atomic in C++17.
// Multiple threads increment a shared atomic counter safely
// and set a flag when done.
#include <atomic>
#include <iostream>
#include <thread>
#include <vector>

std::atomic<int> counter{ 0 };
std::atomic<bool> flag{ false };

void worker(int id)
{
    // Increment the shared counter atomically
    counter.fetch_add(1, std::memory_order_relaxed); // memory_order_relaxed for simple increment

    // The last thread to increment sets the flag
    if (id == 4)
    {
        flag.store(true, std::memory_order_release); // memory_order_release for visibility
    }
}

int main()
{
    std::cout << "Main: Starting atomic counter example.\n";

    std::vector<std::thread> threads;
    for (int i = 0; i < 5; ++i)
    {
        threads.emplace_back(worker, i);
    }

    for (auto &t : threads)
    {
        t.join();
    }

    std::cout << "Main: Final counter value = " << counter.load(std::memory_order_relaxed) << '\n';
    std::cout << "Main: Flag status = " << std::boolalpha << flag.load(std::memory_order_acquire)
              << '\n'; // memory_order_acquire to synchronize with release

    return 0;
}
