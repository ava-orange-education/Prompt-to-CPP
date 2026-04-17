/**
 * @file    function_invocation.cpp
 * @author  Vivek Bhadra
 *
 * @brief
 * Demonstrates invoking a user-defined function to calculate the area
 * of a rectangle.
 *
 * @license
 * This file is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation; either version 3 of the License, or (at your
 * option) any later version.
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 */

// function_invocation.cpp
// This program demonstrates the invocation of a function that calculates the area of a rectangle.
#include <iostream>

// Function to calculate area
double calculateArea(double length, double width)
{
    return length * width;
}

int main()
{
    // Function invocation with arguments
    double area = calculateArea(5.0, 3.0);

    std::cout << "Area: " << area << "\n";
    return 0;
}
