/**
 * @file    fixed_number_printer.cpp
 * @author  Vivek Bhadra
 *
 * @brief
 * Demonstrates a fixed-count iteration using a for loop to print
 * a sequence of numbers.
 *
 * @license
 * This file is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation; either version 3 of the License, or (at your
 * option) any later version.
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 */

// fixed_number_printer.cpp
// This program prints numbers from 0 to 4 using a for loop
#include <iostream>

int main()
{
    for (int i = 0; i < 5; ++i)
    {
        std::cout << i << " ";
    }
    std::cout << "\n";
    return 0;
}