/**
 * @file    off_by_one_bug.cpp
 * @author  Vivek Bhadra
 *
 * @brief
 * Demonstrates an off-by-one error caused by an incorrect loop boundary.
 *
 * @license
 * This file is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation; either version 3 of the License, or (at your
 * option) any later version.
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 */

// off_by_one_bug.cpp
// This program prints numbers from 0 to 5, but it has an off-by-one error
// The loop condition should be i < 5 instead of i <= 5 to avoid printing 5
#include <iostream>

int main()
{
    for (int i = 0; i <= 5; ++i)
    {
        std::cout << i << " ";
    }
    std::cout << "\n";
    return 0;
}