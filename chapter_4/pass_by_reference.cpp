/**
 * @file    pass_by_reference.cpp
 * @author  Vivek Bhadra
 *
 * @brief
 * Demonstrates pass-by-reference parameter passing to modify a variable
 * directly within a function.
 *
 * @license
 * This file is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation; either version 3 of the License, or (at your
 * option) any later version.
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 */

// pass_by_reference.cpp
// This program demonstrates the concept of pass by reference in C++.
#include <iostream>

void increment(int &x)
{
    std::cout << "Before increment (x): " << x << "\n";
    x++;
    std::cout << "After increment (x): " << x << "\n";
}

int main()
{
    int b = 5;
    increment(b);
    std::cout << "After pass by reference (b): " << b << "\n"; // Output: 6
    return 0;
}
