/**
 * @file    c_style_string.cpp
 * @author  Vivek Bhadra
 *
 * @brief
 * Demonstrates the use of C-style strings in C++, including printing
 * with std::cout and manual traversal using a null terminator.
 *
 * @license
 * This file is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation; either version 3 of the License, or (at your
 * option) any later version.
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 */

// c_style_string.cpp
// This program demonstrates the use of C-style strings in C++.
// It shows how to print a C-style string using std::cout and manual traversal.
#include <iostream>

int main()
{
    char name[] = "Alice";

    std::cout << "Using std::cout: " << name << '\n';

    std::cout << "Manual traversal: ";
    for (int i = 0; name[i] != '\0'; ++i)
    {
        std::cout << name[i];
    }
    std::cout << '\n';

    return 0;
}