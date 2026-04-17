/**
 * @file    large_stack_allocation.cpp
 * @author  Vivek Bhadra
 *
 * @brief
 * Demonstrates the risks of large stack allocations in C++.
 *
 * @license
 * This file is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation; either version 3 of the License, or (at your
 * option) any later version.
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 */

// large_stack_allocation.cpp
#include <iostream>
void createLargeArray()
{
    int data[1000000000]; // May exceed stack size
}
int main()
{
    createLargeArray(); // May cause stack overflow
    return 0;
}