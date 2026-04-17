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
// pass_by_reference.cpp
// This program demonstrates the concept of pass by reference in C++.
#include <iostream>

void increment(int &x)
{
    std::cout << "Before increment (x): " << x << "\n";
    x++;
    std::cout << "After increment (x): " << x << "\n";
}

int main()
{
    int b = 5;
    increment(b);
    std::cout << "After pass by reference (b): " << b << "\n"; // Output: 6
    return 0;
}
