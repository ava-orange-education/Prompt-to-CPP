/**
 * @file    file2.cpp
 * @author  Vivek Bhadra
 *
 * @brief
 * Demonstrates cross-file access to a global variable and function using extern.
 *
 * @license
 * This file is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation; either version 3 of the License, or (at your
 * option) any later version.
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 */

// file2.cpp
#include <iostream>

// Declaration only; tells the compiler this exists elsewhere
extern int sharedCount;

void showSharedCount(); // Declaration of function defined in file1.cpp

int main()
{
    std::cout << "Accessing sharedCount from file2.cpp: " << sharedCount << "\n";
    showSharedCount(); // Call function from file1.cpp
    return 0;
}