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
// dynamic_array_demo.cpp
// Demonstrates dynamic array allocation in C++
// This example shows how to allocate, use, and free a dynamic array
#include <iostream>

int main()
{
    // Allocate an array of 5 integers on the heap
    int *arr = new int[5];

    // Initialise the array
    for (int i = 0; i < 5; ++i)
    {
        arr[i] = (i + 1) * 10; // store 10, 20, 30, 40, 50
    }

    // Access and print the array
    std::cout << "Array elements: ";
    for (int i = 0; i < 5; ++i)
    {
        std::cout << arr[i] << " ";
    }
    std::cout << '\n';

    // Release the allocated array
    delete[] arr; // always free memory allocated with new[]

    return 0;
}
