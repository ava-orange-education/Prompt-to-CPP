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

// argument_order_overloading.cpp
// Demonstrates how type, number, and order of arguments affect function overloading in C++.

#include <iostream>

void display(int a)
{
    std::cout << "Function with (int) called\n";
}

void display(double a)
{
    std::cout << "Function with (double) called\n";
}

void display(int a, double b)
{
    std::cout << "Function with (int, double) called\n";
}

void display(double a, int b)
{
    std::cout << "Function with (double, int) called\n";
}

int main()
{
    display(10);      // Calls: display(int)
    display(5.4);     // Calls: display(double)
    display(5, 3.14); // Calls: display(int, double)
    display(3.14, 5); // Calls: display(double, int)

    return 0;
}