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

// short_circuit_simple.cpp
// Demonstrates short-circuit evaluation with && and ||

#include <iostream>

int main()
{
    int a = 5;
    int b = 1;

    std::cout << "--- Testing && (AND) ---\n";
    if (b != 1 && a / b > 1)
    {
        std::cout << "This won't print.\n";
    }
    else
    {
        std::cout << "Second part not evaluated because first condition is false.\n";
    }

    std::cout << "\n--- Testing || (OR) ---\n";
    if (a > 0 || b == 1)
    {
        std::cout << "Second part skipped because the first condition is true.\n";
    }

    return 0;
}