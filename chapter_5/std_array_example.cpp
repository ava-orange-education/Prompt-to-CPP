/**
 * @file    std_array_example.cpp
 * @author  Vivek Bhadra
 *
 * @brief
 * Demonstrates creation, initialisation, and element access of a
 * std::array container in C++.
 *
 * @license
 * This file is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation; either version 3 of the License, or (at your
 * option) any later version.
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 */

// std_array_example.cpp
// This program demonstrates the use of std::array in C++.
// It shows how to create, initialize, and access elements in a std::array.
#include <array>
#include <iostream>

int main()
{
    std::array<int, 5> numbers = {10, 20, 30, 40, 50};

    std::cout << "Elements in std::array: ";
    for (std::size_t i = 0; i < numbers.size(); ++i)
    {
        std::cout << numbers[i] << " ";
    }
    std::cout << '\n';

    return 0;
}