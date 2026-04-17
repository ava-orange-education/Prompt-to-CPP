/**
 * @file    stack_overflow_example.cpp
 * @author  Vivek Bhadra
 *
 * @brief
 * Demonstrates unbounded recursion leading to stack exhaustion in C++.
 *
 * @license
 * This file is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation; either version 3 of the License, or (at your
 * option) any later version.
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 */

// stack_overflow_example.cpp
#include <iostream>
void recursiveFunction()
{
    recursiveFunction();
}
int main()
{
    recursiveFunction(); // Causes stack overflow
    return 0;
}