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

// function_definition.cpp
// This program defines a function to calculate the area of a rectangle and prints the result.
#include <iostream>

// Function definition
double calculateArea(double length, double width)
{
    return length * width;
}

int main()
{
    double l = 5.0;
    double w = 3.0;

    // Function call
    double area = calculateArea(l, w);

    std::cout << "Area: " << area << "\n";

    return 0;
}
