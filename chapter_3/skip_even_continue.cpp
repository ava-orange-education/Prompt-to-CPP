/**
 * @file    skip_even_continue.cpp
 * @author  Vivek Bhadra
 *
 * @brief
 * Demonstrates the use of the continue statement to skip even numbers
 * within a loop.
 *
 * @license
 * This file is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation; either version 3 of the License, or (at your
 * option) any later version.
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 */

// skip_even_continue.cpp
// This program prints odd numbers between 1 and 10.
#include <iostream>
int main()
{
    std::cout << "Odd numbers between 1 and 10:\n";
    for (int i = 1; i <= 10; ++i)
    {
        if (i % 2 == 0)
        {
            continue; // Skip even numbers
        }
        std::cout << i << " ";
    }
    std::cout << "\n";
    return 0;
}