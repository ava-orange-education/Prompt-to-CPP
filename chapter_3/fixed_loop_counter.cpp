/**
 * @file    fixed_loop_counter.cpp
 * @author  Vivek Bhadra
 *
 * @brief
 * Demonstrates a fixed-count loop using a while statement to iterate
 * a known number of times.
 *
 * @license
 * This file is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation; either version 3 of the License, or (at your
 * option) any later version.
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 */

// fixed_loop_counter.cpp
// This program demonstrates a fixed loop counter that prints numbers from 0 to 4
// It uses a while loop with a fixed condition to ensure it runs exactly 5 times
#include <iostream>

int main()
{
    int i = 0;
    while (i < 5)
    {
        std::cout << i << " ";
        i++; // Increment i to eventually make i < 5 false
    }
    std::cout << "\n";
    return 0;
}