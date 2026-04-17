/**
 * @file    pass_by_pointer.cpp
 * @author  Vivek Bhadra
 *
 * @brief
 * Demonstrates pass-by-pointer parameter passing to modify a variable
 * from within a function.
 *
 * @license
 * This file is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation; either version 3 of the License, or (at your
 * option) any later version.
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 */

// pass_by_pointer.cpp
// This program demonstrates the concept of pass by pointer in C++.
#include <iostream>

void increment(int *x)
{
    (*x)++; // Increment the value pointed to by x
}

int main()
{
    int c = 5;
    increment(&c);
    std::cout << "Value of c after calling increment(): " << c << "\n";
    return 0;
}