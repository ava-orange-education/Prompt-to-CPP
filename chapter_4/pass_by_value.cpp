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

// pass_by_value.cpp
// This program demonstrates the concept of pass by value in C++.
#include <iostream>

void increment(int x)
{
    x++;
    std::cout << "Inside function (x): " << x << "\n"; // Shows modified copy
}

int main()
{
    int a = 5;
    increment(a);
    std::cout << "After pass by value (a): " << a << "\n"; // Output: 5
    return 0;
}
