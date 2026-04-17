/**
 * @file    block_scope_exploration.cpp
 * @author  Vivek Bhadra
 *
 * @brief
 * Demonstrates block scope and variable visibility in C++.
 *
 * @license
 * This file is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation; either version 3 of the License, or (at your
 * option) any later version.
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 */

// block_scope_exploration.cpp
#include <iostream>
void showBlockScope()
{
    if (true)
    {
        int x = 5; // x is visible only inside this if block
        std::cout << x << "\n";
    }
    // x is no longer accessible here
    {
        int x = 10; // This is a new x, visible only inside this block
        std::cout << x << "\n";
    }
}
int main()
{
    showBlockScope();
    return 0;
}