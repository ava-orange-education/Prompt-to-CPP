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
// void_pointer_demo.cpp
// Demonstrates the use of void pointers in C++
#include <iostream>

int main()
{
    int value = 42;

    void *voidPtr = &value;                    // void* can store the address of any type
    int *intPtr = static_cast<int *>(voidPtr); // cast back to int* before dereferencing

    std::cout << "Value through int*: " << *intPtr << std::endl;
    return 0;
}
