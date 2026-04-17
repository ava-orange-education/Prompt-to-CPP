/*
 * Copyright (C) 2026
 * Author: Vivek Bhadra
 * 
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program. If not, see <https://www.gnu.org/licenses/>.
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
