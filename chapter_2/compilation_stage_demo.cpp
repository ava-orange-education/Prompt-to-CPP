/**
 * @file    compilation_stage_demo.cpp
 * @author  Vivek Bhadra
 *
 * @brief
 * Demonstrates compile-time warnings and errors in C++.
 *
 * @license
 * This file is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation; either version 3 of the License, or (at your
 * option) any later version.
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 */

// compilation_stage_demo.cpp
#include <iostream>
int main()
{
    int x = 3.14;            // Warning: narrowing conversion
    std::cout << x return 0; // Error: missing semicolon before
}