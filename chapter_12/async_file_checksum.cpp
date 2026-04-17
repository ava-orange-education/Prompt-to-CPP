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
// async_file_checksum.cpp
// This code demonstrates asynchronous file checksum computation in C++17.
// A separate thread computes the checksum of a file while the main thread
// continues executing other tasks. The result is retrieved using std::future.
#include <chrono>
#include <fstream>
#include <future>
#include <iostream>
#include <string>
#include <thread>

// Function that simulates reading a file and computing a checksum
unsigned long compute_checksum(const std::string &filename)
{
    std::ifstream file(filename, std::ios::binary);
    if (!file)
    {
        throw std::runtime_error("Failed to open file");
    }

    unsigned long checksum = 0;
    char byte;
    while (file.get(byte))
    {
        checksum += static_cast<unsigned long>(
            static_cast<unsigned char>(byte));
    }

    return checksum;
}

int main()
{
    std::cout << "Main: Launching checksum task asynchronously.\n";

    // Launch the task asynchronously
    std::future<unsigned long> result = std::async(std::launch::async, compute_checksum, "data_log.txt");

    std::cout << "Main: Performing other work while checksum is computed.\n";
    std::this_thread::sleep_for(std::chrono::milliseconds(300));

    // Retrieve result (blocks if computation not yet finished)
    unsigned long checksum = result.get();
    std::cout << "Main: Final checksum value = " << checksum << "\n";

    return 0;
}
