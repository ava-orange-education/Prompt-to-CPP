/**
 * @file    static_variable_lifetime.cpp
 * @author  Vivek Bhadra
 *
 * @brief
 * Demonstrates the lifetime of a static local variable across function calls.
 *
 * @license
 * This file is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation; either version 3 of the License, or (at your
 * option) any later version.
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 */

// static_variable_lifetime.cpp
#include <iostream>
void testStatic()
{
    static int counter = 0;
    counter++;
    std::cout << counter << "\n";
}
int main()
{
    testStatic(); // Outputs 1
    testStatic(); // Outputs 2
    return 0;
}