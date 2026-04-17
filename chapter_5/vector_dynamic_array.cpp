/**
 * @file    vector_dynamic_array.cpp
 * @author  Vivek Bhadra
 *
 * @brief
 * Demonstrates the use of std::vector as a dynamic array, including
 * dynamic insertion, safe element access, and traversal.
 *
 * @license
 * This file is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation; either version 3 of the License, or (at your
 * option) any later version.
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 */

// vector_dynamic_array.cpp
// Demonstrates how std::vector can be used as a dynamic array in C++
#include <iostream>
#include <vector>

int main()
{
    std::vector<int> scores; // Empty vector

    // Adding elements dynamically
    scores.push_back(85);
    scores.push_back(90);
    scores.push_back(78);

    // Accessing and modifying elements
    std::cout << "First score: " << scores[0] << '\n';
    scores.at(2) = 80; // safely modifying the third score

    // Traversing using index-based loop
    std::cout << "All scores: ";
    for (std::size_t i = 0; i < scores.size(); ++i)
    {
        std::cout << scores[i] << " ";
    }
    std::cout << '\n';

    return 0;
}
