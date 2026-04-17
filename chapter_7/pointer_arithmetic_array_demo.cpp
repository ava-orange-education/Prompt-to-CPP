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
// pointer_arithmetic_array_demo.cpp
// Demonstrates pointer arithmetic in C++ with detailed examples

#include <cstddef> // for std::ptrdiff_t
#include <iostream>

int main()
{
    int arr[4] = {10, 20, 30, 40};

    int *p = arr; // arr decays to pointer to first element
    std::cout << "Initial pointer address: " << p << ", value: " << *p << '\n';

    // Increment the pointer
    ++p;
    std::cout << "After ++p -> address: " << p << ", value: " << *p << " (moved by sizeof(int) = " << sizeof(int)
              << " bytes)\n";

    // Pointer addition
    std::cout << "At p + 1 -> address: " << (p + 1) << ", value: " << *(p + 1) << '\n';

    // Reset pointer to beginning
    p = arr;

    // Traverse array using pointer arithmetic
    std::cout << "Traversing array:\n";
    for (int i = 0; i < 4; ++i)
    {
        std::cout << "p + " << i << " -> address: " << (p + i) << ", value: " << *(p + i) << '\n';
    }

    // Pointer subtraction
    int *start = &arr[0];
    int *end = &arr[4]; // one past the last element
    std::ptrdiff_t distance = end - start;

    std::cout << "Number of elements between start and end: " << distance << '\n';

    return 0;
}