/**
 * @file    array_reversal_ai.cpp
 * @author  Vivek Bhadra
 *
 * @brief
 * Demonstrates reversing a fixed-size array using std::reverse and
 * std::array from the C++ Standard Library.
 *
 * @license
 * This file is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation; either version 3 of the License, or (at your
 * option) any later version.
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 */

// array_reversal_ai.cpp
// This program demonstrates how to reverse an array using std::reverse from the C++ Standard Library.
// It uses std::array for fixed-size arrays and prints the reversed array.
#include <algorithm>
#include <array>
#include <iostream>

int main()
{
    std::array<int, 5> data = {1, 2, 3, 4, 5};
    std::reverse(data.begin(), data.end());

    for (int x : data)
    {
        std::cout << x << ' ';
    }

    return 0;
}