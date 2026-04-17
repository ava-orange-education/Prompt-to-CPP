/**
 * @file    infinite_loop_bug.cpp
 * @author  Vivek Bhadra
 *
 * @brief
 * Demonstrates an infinite loop caused by a missing loop counter update.
 *
 * @license
 * This file is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation; either version 3 of the License, or (at your
 * option) any later version.
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 */

// infinite_loop_bug.cpp
// This program demonstrates an infinite loop due to a missing increment in the loop condition
#include <iostream>

int main()
{
    int i = 0;
    while (i < 5)
    {
        std::cout << i << " ";
        // Missing increment: i++ needed to reach i >= 5
    }
    return 0;
}