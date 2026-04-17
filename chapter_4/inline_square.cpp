/**
 * @file    inline_square.cpp
 * @author  Vivek Bhadra
 *
 * @brief
 * Demonstrates the use of an inline function to compute the square
 * of an integer value.
 *
 * @license
 * This file is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation; either version 3 of the License, or (at your
 * option) any later version.
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 */

// inline_square.cpp
// This program demonstrates an inline function in C++.

#include <iostream>

inline int square(int x)
{
    return x * x;
}

int main()
{
    std::cout << "Square of 4: " << square(4) << "\n";   // Output: 16
    std::cout << "Square of 10: " << square(10) << "\n"; // Output: 100
    return 0;
}