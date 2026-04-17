/**
 * @file    null_terminator.cpp
 * @author  Vivek Bhadra
 *
 * @brief
 * Demonstrates the use of sizeof on a C-style string array to show
 * the total array size including the null terminator.
 *
 * @license
 * This file is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation; either version 3 of the License, or (at your
 * option) any later version.
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 */

#include <iostream>

int main()
{
    char name[] = "Alice";

    // for (int i = 0; name[i] != '\0'; ++i)
    // {
    //     std::cout << name[i] << " ";
    // }
    std::cout << sizeof(name) << std::endl; // Outputs the size of the array including the null terminator

    return 0;
};