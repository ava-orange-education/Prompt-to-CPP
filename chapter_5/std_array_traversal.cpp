/**
 * @file    std_array_access.cpp
 * @author  Vivek Bhadra
 *
 * @brief
 * Demonstrates element access and traversal of a std::array using
 * operator[] and the bounds-checked at() member function.
 *
 * @license
 * This file is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation; either version 3 of the License, or (at your
 * option) any later version.
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 */

// std_array_access.cpp
// This program demonstrates how to access elements in a std::array in C++.
// It shows the use of both operator[] and .at() for element access.
// It also illustrates how to traverse the array and print its elements.
#include <array>
#include <iostream>

int main()
{
    std::array<int, 5> numbers = {10, 20, 30, 40, 50};

    // Accessing elements using operator[] and .at()
    std::cout << "First element (operator[]): " << numbers[0] << '\n';
    std::cout << "Third element (.at()): " << numbers.at(2) << '\n';
    std::cout << "Total number of elements: " << numbers.size() << '\n';

    // Traversing the array
    std::cout << "Array elements: ";
    for (std::size_t i = 0; i < numbers.size(); ++i)
    {
        std::cout << numbers[i] << ' ';
    }
    std::cout << '\n';

    return 0;
}