/**
 * @file    number_sequence_printer.cpp
 * @author  Vivek Bhadra
 *
 * @brief
 * Prints a sequence of numbers from 1 to 10 using a for loop.
 *
 * @license
 * This file is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation; either version 3 of the License, or (at your
 * option) any later version.
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 */

// number_sequence_printer.cpp
// This program prints numbers from 1 to 10.
#include <iostream>

int main()
{
    std::cout << "Numbers from 1 to 10:\n";
    for (int i = 1; i <= 10; i++)
    {
        std::cout << i << " ";
    }
    std::cout << "\n";
    return 0;
}