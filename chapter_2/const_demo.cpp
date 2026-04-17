/**
 * @file    const_demo.cpp
 * @author  Vivek Bhadra
 *
 * @brief
 * Demonstrates the use of the const qualifier to prevent modification of variables.
 *
 * @license
 * This file is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation; either version 3 of the License, or (at your
 * option) any later version.
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 */

// const_demo.cpp
#include <iostream>

int main()
{
    const float PI = 3.14159f;

    std::cout << "Value of PI (const): " << PI << "\n";

    // Uncommenting the following line will cause a compile-time error:
    // PI = 3.14f; // Error: assignment of read-only variable 'PI'

    return 0;
}