/**
 * @file    function_overloading.cpp
 * @author  Vivek Bhadra
 *
 * @brief
 * Demonstrates function overloading by defining multiple functions with
 * the same name but different parameter types.
 *
 * @license
 * This file is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation; either version 3 of the License, or (at your
 * option) any later version.
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 */

// function_overloading.cpp
// This program demonstrates function overloading in C++.
#include <iostream>

int add(int a, int b)
{
    return a + b;
}

double add(double a, double b)
{
    return a + b;
}

int main()
{
    std::cout << add(3, 4) << '\n';     // Calls int version: outputs 7
    std::cout << add(3.5, 4.2) << '\n'; // Calls double version: outputs 7.7
    return 0;
}