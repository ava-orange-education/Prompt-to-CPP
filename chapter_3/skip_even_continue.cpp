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

// skip_even_continue.cpp
// This program prints odd numbers between 1 and 10.
#include <iostream>
int main()
{
    std::cout << "Odd numbers between 1 and 10:\n";
    for (int i = 1; i <= 10; ++i)
    {
        if (i % 2 == 0)
        {
            continue; // Skip even numbers
        }
        std::cout << i << " ";
    }
    std::cout << "\n";
    return 0;
}