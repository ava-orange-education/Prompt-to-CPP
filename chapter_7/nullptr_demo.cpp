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
// nullptr_demo.cpp
// Demonstrates the use of nullptr in C++ for safe pointer initialization
#include <iostream>

int main()
{
    // Safely initialised pointer: clearly indicates "no object"
    int *safePtr = nullptr;

    if (!safePtr)
    {
        std::cout << "safePtr is not assigned yet." << "\n";
    }

    int number = 42;
    safePtr = &number; // now points to a valid object

    if (safePtr)
    {
        std::cout << "safePtr is valid, value = " << *safePtr << "\n";
    }

    // Potential danger: uninitialised pointer holds an indeterminate address
    int *dangerousPtr; // uninitialised
    // if(dangerousPtr) { // as this is uninitialised, it may point to a random memory location
    //     std::cout << "dangerousPtr is valid, value = " << *dangerousPtr << "\n"; // may crash
    // } else {
    //     std::cout << "dangerousPtr is not assigned yet." << "\n"; // may not be reached if it points to invalid
    //     memory
    // }
    // Uncommenting the above code may lead to undefined behavior
    return 0;
}
