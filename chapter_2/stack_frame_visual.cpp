/**
 * @file    stack_frame_visual.cpp
 * @author  Vivek Bhadra
 *
 * @brief
 * Demonstrates function calls and local variable usage within a stack frame.
 *
 * @license
 * This file is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation; either version 3 of the License, or (at your
 * option) any later version.
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 */

// stack_frame_visual.cpp
#include <iostream>
int foo(int x, int y)
{
    int z = x + y;
    return z;
}
int main()
{
    int m = 5;
    int n = 6;
    int p = 0;
    p = foo(m, n);
    std::cout << "Result of addition z = " << p << "\n";
    return 0;
}