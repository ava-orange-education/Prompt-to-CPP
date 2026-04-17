/**
 * @file    local_variable_scope.cpp
 * @author  Vivek Bhadra
 *
 * @brief
 * Demonstrates the scope of a local variable within a function.
 *
 * @license
 * This file is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation; either version 3 of the License, or (at your
 * option) any later version.
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 */

// local_variable_scope.cpp
#include <iostream>
void showLocal()
{
    int localVar = 42; // localVar is accessible only within this function
}
int main()
{
    showLocal(); // localVar not accessible here
    return 0;
}