/**
 * @file    c_style_string_strlen.cpp
 * @author  Vivek Bhadra
 *
 * @brief
 * Demonstrates efficient traversal of a C-style string by computing
 * its length once using std::strlen.
 *
 * @license
 * This file is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation; either version 3 of the License, or (at your
 * option) any later version.
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 */

// c_style_string_strlen.cpp
// This program demonstrates efficient traversal of a C-style string
// using std::strlen by storing the length beforehand.

#include <cstring> // Required for std::strlen
#include <iostream>

int main()
{
    char name[] = "Alice";

    std::size_t length = std::strlen(name); // Store length once for efficiency

    std::cout << "Using std::strlen for traversal: ";
    for (std::size_t i = 0; i < length; ++i)
    {
        std::cout << name[i];
    }
    std::cout << '\n';

    return 0;
}
