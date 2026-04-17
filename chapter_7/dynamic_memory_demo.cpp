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
// dynamic_memory_demo.cpp
// Demonstrates dynamic memory allocation in C++
#include <iostream>

int main()
{
    // Allocate a single int on the heap, initialised to 42
    int *p = new int(42);

    std::cout << "Value at allocated memory: " << *p << '\n';
    std::cout << "Address of allocated memory: " << p << '\n';

    // Release the allocated memory
    delete p;
    p = nullptr; // good practice to avoid dangling pointer

    return 0;
}