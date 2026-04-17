/**
 * @file    narrowing_conversion_warning.cpp
 * @author  Vivek Bhadra
 *
 * @brief
 * Demonstrates a compile-time error caused by a narrowing conversion
 * using brace initialisation in C++.
 *
 * @license
 * This file is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation; either version 3 of the License, or (at your
 * option) any later version.
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 */

// narrowing_conversion_warning.cpp
#include <iostream>
int main()
{
    int x{4.2}; // Narrowing conversion warning
    return 0;
}