/**
 * @file    <filename>
 * @author  Vivek Bhadra
 *
 * @brief
 * Demonstrates copy, direct, and uniform initialisation and their behaviour
 * with respect to narrowing conversions in C++.
 *
 * @license
 * This file is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation; either version 3 of the License, or (at your
 * option) any later version.
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 */

#include <iostream>
int main()
{
    // Copy initialisation - allows implicit narrowing
    int a = 4.2; // Allowed, but value becomes 4

    // Direct initialisation - also allows implicit narrowing
    int b(4.2); // Allowed, but value becomes 4

    // Uniform initialisation - prevents narrowing at compile time
    // int c{4.2}; // Error: narrowing conversion from double to int
    int c{4}; // Valid initialisation with no narrowing

    std::cout << "Copy initialized a = " << a << "\n";
    std::cout << "Direct initialized b = " << b << "\n";
    std::cout << "Uniform initialized c = " << c << "\n";

    return 0;
}
