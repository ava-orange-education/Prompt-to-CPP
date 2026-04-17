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
// condition_variable_example.cpp
// This code demonstrates the use of std::condition_variable in C++17.
// A producer thread generates data and notifies a consumer thread,
// which waits until data becomes available before processing it.

#include <condition_variable>
#include <iostream>
#include <mutex>
#include <thread>
#include <vector>

std::mutex mtx;
std::condition_variable cv;
std::vector<int> shared_data;
bool ready = false;

void producer()
{
    {
        std::lock_guard<std::mutex> lock(mtx);
        shared_data.push_back(42); // Produce data
        ready = true;
        std::cout << "Producer: data produced.\n";
    }
    cv.notify_one(); // Notify one waiting thread
}

void consumer()
{
    std::unique_lock<std::mutex> lock(mtx);
    cv.wait(lock, [] { return ready; }); // Wait until data is available

    int value = shared_data.back();
    shared_data.pop_back(); // Consume data
    std::cout << "Consumer: consumed value -> " << value << '\n';
}

int main()
{
    std::thread t1(consumer);
    std::thread t2(producer);

    t1.join();
    t2.join();

    return 0;
}

