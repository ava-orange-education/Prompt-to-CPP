/**
 * @file    usage_of_at_method.cpp
 * @author  Vivek Bhadra
 *
 * @brief
 * Demonstrates safe, bounds-checked element access using the at()
 * member function of std::array and handling out-of-range exceptions.
 *
 * @license
 * This file is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation; either version 3 of the License, or (at your
 * option) any later version.
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 */

// usage_of_at_method.cpp
// This program demonstrates the use of the at() method in std::array
// to safely access elements and handle out-of-bounds access.
#include <array>
#include <iostream>

int main()
{
    std::array<int, 3> data = {10, 20, 30};

    try
    {
        std::cout << "Accessing data.at(5): ";
        std::cout << data.at(5) << '\n'; // Throws std::out_of_range
    }
    catch (const std::out_of_range &e)
    {
        std::cout << "Caught exception: " << e.what() << '\n';
    }

    return 0;
}
