/**
 * @file    stack_vs_heap_allocation.cpp
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

// stack_vs_heap_allocation.cpp
#include <iostream>

// Stack allocation: memory is automatically released when the function exits
void useStackMemory()
{
    int stackValue = 10;
    std::cout << "Stack value: " << stackValue << "\n";
}

// Heap allocation: memory remains valid after the function returns
int *allocateHeapMemory()
{
    int *heapValue = new int(20); // Allocate on heap
    return heapValue;             // Return pointer to allocated heap memory
}

int main()
{
    useStackMemory(); // Variable created and destroyed inside the function

    int *heapPtr = allocateHeapMemory();                  // Heap memory still exists
    std::cout << "Heap value: " << *heapPtr << "\n"; // Dereference pointer to access value

    delete heapPtr;    // Clean up
    heapPtr = nullptr; // Safe practice

    return 0;
}
