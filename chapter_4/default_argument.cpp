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

// default_argument.cpp
// This program demonstrates the use of default arguments in C++.
#include <iostream>

double calculateArea(double length, double width = 1.0)
{
    return length * width;
}

int main()
{
    std::cout << "Area with one argument: " << calculateArea(5.0) << "\n";       // Output: 5.0
    std::cout << "Area with two arguments: " << calculateArea(5.0, 3.0) << "\n"; // Output: 15.0
    return 0;
}