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