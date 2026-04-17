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
// array_pointer_pize.cpp
// Demonstrates the size of an array and a pointer to an array in C++

#include <iostream>

int main()
{
    int arr[3] = {10, 20, 30}; // An array of 3 integers
    int *p = arr;              // arr decays to pointer to first element

    std::cout << "sizeof(arr): " << sizeof(arr) << '\n'; // size of whole array (e.g., 12 bytes if int is 4 bytes)
    std::cout << "sizeof(p):   " << sizeof(p) << '\n';   // size of pointer (e.g., 8 bytes on a 64-bit system)

    return 0;
}
