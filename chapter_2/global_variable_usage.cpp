/**
 * @file    global_variable_usage.cpp
 * @author  Vivek Bhadra
 *
 * @brief
 * Demonstrates the definition and use of a global variable in C++.
 *
 * @license
 * This file is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation; either version 3 of the License, or (at your
 * option) any later version.
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 */

// global_variable_usage.cpp
#include <iostream>
int globalVar = 100; // global variable
void useGlobal()
{
    std::cout << "Value of globalVar: " << globalVar << "\n";
}
int main()
{
    useGlobal();
    return 0;
}