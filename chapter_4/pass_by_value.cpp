/**
 * @file    pass_by_value.cpp
 * @author  Vivek Bhadra
 *
 * @brief
 * Demonstrates pass-by-value parameter passing where a function
 * operates on a copy of the argument.
 *
 * @license
 * This file is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation; either version 3 of the License, or (at your
 * option) any later version.
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 */

// pass_by_value.cpp
// This program demonstrates the concept of pass by value in C++.
#include <iostream>

void increment(int x)
{
    x++;
    std::cout << "Inside function (x): " << x << "\n"; // Shows modified copy
}

int main()
{
    int a = 5;
    increment(a);
    std::cout << "After pass by value (a): " << a << "\n"; // Output: 5
    return 0;
}
