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
// unique_lock_flexible.cpp
// This code demonstrates the flexible locking capabilities of std::unique_lock in C++17.
// A worker thread conditionally acquires a lock based on a shared flag
// to update a shared counter variable.
#include <atomic>
#include <chrono>
#include <iostream>
#include <mutex>
#include <thread>

std::mutex mtx;
int shared_counter = 0;
std::atomic<bool> enable_update{false};

void worker_thread()
{
    std::unique_lock<std::mutex> lock(mtx, std::defer_lock); // Lock deferred

    // Simulate some preparation work before acquiring the lock
    std::this_thread::sleep_for(std::chrono::milliseconds(200));

    if (!enable_update.load())
    {
        std::cout << "Worker: Update disabled, skipping critical section.\n";
        return;
    }

    lock.lock(); // Lock only when condition is true
    std::cout << "Worker: Lock acquired, updating shared counter...\n";
    shared_counter += 10;
    std::this_thread::sleep_for(std::chrono::milliseconds(300));
    lock.unlock(); // Manual unlock

    std::cout << "Worker: Lock released after update.\n";
}

int main()
{
    std::cout << "Main: Preparing system...\n";
    std::thread t(worker_thread);

    std::this_thread::sleep_for(std::chrono::milliseconds(100));
    enable_update.store(true);
    std::cout << "Main: Update enabled.\n";

    t.join();
    std::cout << "Main: Final shared counter = " << shared_counter << '\n';
    return 0;
}