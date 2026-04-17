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

// pass_by_pointer.cpp
// This program demonstrates the concept of pass by pointer in C++.
#include <iostream>

void increment(int *x)
{
    (*x)++; // Increment the value pointed to by x
}

int main()
{
    int c = 5;
    increment(&c);
    std::cout << "Value of c after calling increment(): " << c << "\n";
    return 0;
}