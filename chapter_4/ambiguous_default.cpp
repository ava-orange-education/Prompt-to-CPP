/**
 * @file    ambiguous_default.cpp
 * @author  Vivek Bhadra
 *
 * @brief
 * Demonstrates a compile-time ambiguity caused by combining function
 * overloading with default arguments in C++.
 *
 * @license
 * This file is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation; either version 3 of the License, or (at your
 * option) any later version.
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 */

// ambiguous_default.cpp
// Demonstrates default argument mixed with overloading causes ambiguity in C++.
#include <iostream>
void print(int a, int b = 10)
{
    std::cout << "Function with (int, int) called\n";
}

void print(int a)
{
    std::cout << "Function with (int) called\n";
}

int main()
{
    print(10); // ambiguous call, could be print(int) or print(int, int)
    print(5, 3);
    return 0;
}