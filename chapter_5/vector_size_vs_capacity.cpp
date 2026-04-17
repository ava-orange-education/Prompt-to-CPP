/**
 * @file    vector_size_vs_capacity.cpp
 * @author  Vivek Bhadra
 *
 * @brief
 * Demonstrates the difference between size and capacity in std::vector
 * by observing how they change during element insertion and memory
 * reservation.
 *
 * @license
 * This file is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation; either version 3 of the License, or (at your
 * option) any later version.
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 */

// vector_size_vs_capacity.cpp
// This program demonstrates the difference between size and capacity of a vector
// in C++. It shows how to reserve memory, add elements, and observe changes in size
#include <iostream>
#include <vector>

int main()
{
    std::vector<int> numbers;

    std::cout << "Initial state:\n";
    std::cout << "Size: " << numbers.size() << '\n';
    std::cout << "Capacity: " << numbers.capacity() << "\n\n";

    numbers.push_back(1);
    std::cout << "After push_back(1):\n";
    std::cout << "Size: " << numbers.size() << '\n';
    std::cout << "Capacity: " << numbers.capacity() << "\n\n";

    numbers.push_back(2);
    std::cout << "After push_back(2):\n";
    std::cout << "Size: " << numbers.size() << '\n';
    std::cout << "Capacity: " << numbers.capacity() << "\n\n";

    numbers.push_back(3);
    std::cout << "After push_back(3):\n";
    std::cout << "Size: " << numbers.size() << '\n';
    std::cout << "Capacity: " << numbers.capacity() << "\n\n";

    numbers.push_back(4);
    std::cout << "After push_back(4):\n";
    std::cout << "Size: " << numbers.size() << '\n';
    std::cout << "Capacity: " << numbers.capacity() << "\n\n";

    numbers.push_back(5);
    std::cout << "After push_back(5):\n";
    std::cout << "Size: " << numbers.size() << '\n';
    std::cout << "Capacity: " << numbers.capacity() << "\n\n";

    numbers.reserve(20);
    std::cout << "After reserve(20):\n";
    std::cout << "Size: " << numbers.size() << '\n';
    std::cout << "Capacity: " << numbers.capacity() << "\n";

    return 0;
}
