/**
 * @file    type_conversions.cpp
 * @author  Vivek Bhadra
 *
 * @brief
 * Demonstrates an implicit type conversion from double to int and the
 * resulting loss of the fractional part.
 *
 * @license
 * This file is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation; either version 3 of the License, or (at your
 * option) any later version.
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 */

// type_conversions.cpp
#include <iostream>
int main()
{
    double pi = 3.14159;
    int truncated = pi; // Implicit conversion, fractional part lost
    std::cout << "Double pi = " << pi << "\n";
    std::cout << "Truncated int = " << truncated << "\n";
    return 0;
}