/**
 * @file    stack_trace.cpp
 * @author  Vivek Bhadra
 *
 * @brief
 * Demonstrates function call flow and call stack behaviour through
 * nested function calls in C++.
 *
 * @license
 * This file is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation; either version 3 of the License, or (at your
 * option) any later version.
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 */

// stack_trace.cpp
// Demonstrates function call stack behavior in C++.
#include <iostream>

void inner(int x)
{
    std::cout << "Inner: x = " << x << "\n";
}

void outer(int y)
{
    inner(y + 1);
}

int main()
{
    outer(5);
    return 0;
}
