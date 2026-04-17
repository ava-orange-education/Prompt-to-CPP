/**
 * @file    parameter_passing.cpp
 * @author  Vivek Bhadra
 *
 * @brief
 * Demonstrates different parameter passing mechanisms in C++ including
 * pass-by-value, pass-by-reference, and pass-by-pointer.
 *
 * @license
 * This file is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation; either version 3 of the License, or (at your
 * option) any later version.
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 */

// parameter_passing.cpp
// This program demonstrates different methods of parameter passing in C++.
#include <iostream>

void byValue(int x)
{
    x++;
}

void byReference(int &x)
{
    x++;
}

void byPointer(int *x)
{
    (*x)++;
}

int main()
{
    int a = 5, b = 5, c = 5;

    byValue(a);
    byReference(b);
    byPointer(&c);

    std::cout << "Value of a after passing byValue(): " << a << "\n";     // Output: 5
    std::cout << "Value of b after passing byReference(): " << b << "\n"; // Output: 6
    std::cout << "Value of c after passing byPointer(): " << c << "\n";   // Output: 6

    return 0;
}