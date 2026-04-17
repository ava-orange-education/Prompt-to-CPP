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

// array_indexing_char.cpp
// This program demonstrates how to declare a char array and access its elements using indexing in C++.
#include <iostream>

int main()
{
    // Declare and initialise a char array
    char letters[5] = {'A', 'B', 'C', 'D', 'E'};

    // Access and print each element using indexing
    std::cout << "First letter: " << letters[0] << "\n";
    std::cout << "Second letter: " << letters[1] << "\n";
    std::cout << "Third letter: " << letters[2] << "\n";
    std::cout << "Fourth letter: " << letters[3] << "\n";
    std::cout << "Fifth letter: " << letters[4] << "\n";

    return 0;
}