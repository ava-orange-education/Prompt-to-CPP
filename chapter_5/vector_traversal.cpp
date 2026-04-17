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
// vector_traversal.cpp
// Demonstrates different methods of traversing and modifying a vector in C++.
#include <iostream>
#include <vector>

int main()
{
    std::vector<int> values = {1, 2, 3, 4, 5, 6};

    for(int val : values)
        val = val + 1;  // Modifies only the copy, not the original vector
    
    for(int val : values)
        std::cout << val << " ";
    std::cout << "\n";

    for(int& val : values)
        val = val + 1;  // Modifies the original vector
    for(int& val : values)
        std::cout << val << " ";
    std::cout << "\n";

    for(const int& val : values)
    {
        // val = val + 1;  // Error: cannot modify a const reference
        std::cout << val << " ";
    }
    std::cout << "\n";

    return 0;
}
