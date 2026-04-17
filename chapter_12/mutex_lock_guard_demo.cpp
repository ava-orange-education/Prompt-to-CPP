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
// mutex_lock_guard_demo.cpp
// Demonstrates basic mutual exclusion using std::mutex and std::lock_guard.
// Two threads increment a shared counter safely without race conditions.

#include <iostream>
#include <mutex>
#include <thread>

std::mutex mtx;
int counter = 0;

void worker()
{
    for (int i = 0; i < 100000; ++i)
    {
        std::lock_guard<std::mutex> lock(mtx); // Lock acquired automatically
        ++counter;                             // Safe increment
    }
    // Lock is released automatically when lock goes out of scope
}

int main()
{
    std::thread t1(worker);
    std::thread t2(worker);

    t1.join();
    t2.join();

    std::cout << "Final counter value: " << counter << '\n';
    return 0;
}
