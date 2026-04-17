/**
 * @file    default_argument.cpp
 * @author  Vivek Bhadra
 *
 * @brief
 * Demonstrates the use of default arguments in a function definition.
 *
 * @license
 * This file is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation; either version 3 of the License, or (at your
 * option) any later version.
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 */

// default_argument.cpp
// This program demonstrates the use of default arguments in C++.
#include <iostream>

double calculateArea(double length, double width = 1.0)
{
    return length * width;
}

int main()
{
    std::cout << "Area with one argument: " << calculateArea(5.0) << "\n";       // Output: 5.0
    std::cout << "Area with two arguments: " << calculateArea(5.0, 3.0) << "\n"; // Output: 15.0
    return 0;
}