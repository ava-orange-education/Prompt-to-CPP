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
// calibrated_reduction_main.cpp
// This code demonstrates the use of std::condition_variable with notify_all in C++17.
// A producer thread generates data for multiple consumers and notifies all of them.
// Each consumer waits until data is available and then consumes one item.

#include <chrono>
#include <condition_variable>
#include <iostream>
#include <mutex>
#include <thread>
#include <vector>

std::mutex mtx;
std::condition_variable cv;
bool ready = false;
std::vector<int> shared_data;   // Shared data container

void consumer(int id)
{
    std::unique_lock<std::mutex> lock(mtx);
    std::cout << "Consumer " << id << ": waiting for data...\n";

    // Wait until 'ready' becomes true
    cv.wait(lock, [] { return ready; });

    // Consume one item
    int value = shared_data.back();
    shared_data.pop_back();

    std::cout << "Consumer " << id << ": consumed value " << value << '\n';
}

void producer(std::size_t consumer_count)
{
    std::this_thread::sleep_for(std::chrono::milliseconds(500)); // Simulate preparation

    {
        std::lock_guard<std::mutex> lock(mtx); // Lock the mutex
        // Produce exactly one item per consumer
	for (std::size_t i = 0; i < consumer_count; ++i)
        {
            shared_data.emplace_back(static_cast<int>(i + 1));
        }

        ready = true;                          // Set the flag to true
        std::cout << "Producer: data prepared for all consumers.\n";
    } // Unlocks mutex here

    // Wake up all waiting consumers
    cv.notify_all();
}

int main()
{
    std::cout << "Main: Starting producer and multiple consumers.\n";

    const std::size_t consumer_count = 3;

    // Launch consumers
    std::vector<std::thread> consumers;
    for (std::size_t i = 1; i <= consumer_count; ++i)
    {
        consumers.emplace_back(consumer, static_cast<int>(i));
    }

    // Launch producer
    std::thread prod(producer, consumer_count);

    // Join all threads
    for (auto &t : consumers)
    {
        t.join();
    }
    prod.join();

    std::cout << "Main: All consumers have processed their data.\n";
    return 0;
}
