/**
 * @file    array_size_function.cpp
 * @author  Vivek Bhadra
 *
 * @brief
 * Demonstrates the use of std::array and its size() member function
 * to determine the number of elements in a fixed-size array.
 *
 * @license
 * This file is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation; either version 3 of the License, or (at your
 * option) any later version.
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 */

// array_size_function.cpp
// This program demonstrates how to use std::array and its size() function
// to traverse an array and print its elements in C++.

#include <array>
#include <iostream>

int main()
{
    std::array<int, 5> numbers = {10, 20, 30, 40, 50};

    std::cout << "The array contains " << numbers.size() << " elements.\n";

    return 0;
}
