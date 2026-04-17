/**
 * @file    function_definition.cpp
 * @author  Vivek Bhadra
 *
 * @brief
 * Demonstrates defining a function to calculate the area of a rectangle
 * and invoking it from main.
 *
 * @license
 * This file is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation; either version 3 of the License, or (at your
 * option) any later version.
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
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
