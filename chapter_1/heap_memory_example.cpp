/**
 * @file    heap_memory_example.cpp
 * @author  Vivek Bhadra
 *
 * @brief
 * Demonstrates the difference between stack and heap memory allocation in C++.
 *
 * @license
 * This file is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation; either version 3 of the License, or (at your
 * option) any later version.
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 */

// heap_memory_example.cpp 
// This example demonstrates the difference between stack and heap memory allocation in C++.
#include <iostream>

// Stack allocation: allocated memory is automatically released when the function exits
void useStackMemory()
{
    int stackValue = 10;
    std::cout << "Stack value: " << stackValue << std::endl;
}

// Heap allocation: allocated memory remains valid even after the function returns
int *allocateHeapMemory()
{
    int *heapValue = new int(20); // Allocate on heap
    return heapValue;             // Return pointer to allocated heap memory
}

int main()
{
    useStackMemory(); // Variable created and destroyed inside the function
                      // Stack memory is automatically cleaned up when the function exits

    int *heapPtr = allocateHeapMemory();                  // Heap memory still exists
    std::cout << "Heap value: " << *heapPtr << std::endl; // Dereference pointer to access value

    delete heapPtr;    // Clean up
    heapPtr = nullptr; // Safe practice

    return 0;
}
