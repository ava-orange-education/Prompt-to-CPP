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

// c_style_string_strlen.cpp
// This program demonstrates efficient traversal of a C-style string
// using std::strlen by storing the length beforehand.

#include <cstring> // Required for std::strlen
#include <iostream>

int main()
{
    char name[] = "Alice";

    std::size_t length = std::strlen(name); // Store length once for efficiency

    std::cout << "Using std::strlen for traversal: ";
    for (std::size_t i = 0; i < length; ++i)
    {
        std::cout << name[i];
    }
    std::cout << '\n';

    return 0;
}
