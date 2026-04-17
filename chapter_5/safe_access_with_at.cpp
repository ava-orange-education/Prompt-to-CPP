/**
 * @file    safe_access_with_at.cpp
 * @author  Vivek Bhadra
 *
 * @brief
 * Demonstrates safe, bounds-checked element access using the at()
 * member function of std::array.
 *
 * @license
 * This file is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation; either version 3 of the License, or (at your
 * option) any later version.
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 */

// safe_access_with_at.cpp
// This program demonstrates the use of the at() method in std::array
// to safely access elements and handle out-of-bounds access.
#include <array>
#include <iostream>

int main()
{
    std::array<int, 3> data = {10, 20, 30};

    std::cout << "Accessing valid indices with .at():\n";
    std::cout << "data.at(0) = " << data.at(0) << '\n';
    std::cout << "data.at(2) = " << data.at(2) << '\n';

    // std::cout << data.at(5); // Uncommenting this line will throw an exception std::out_of_range

    return 0;
}
