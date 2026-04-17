/**
 * @file    fallthrough_demo.cpp
 * @author  Vivek Bhadra
 *
 * @brief
 * Demonstrates switch-case fallthrough behaviour when break statements
 * are omitted.
 *
 * @license
 * This file is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation; either version 3 of the License, or (at your
 * option) any later version.
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 */

// fallthrough_demo.cpp
// Demonstrates what happens when break statements are missing in a switch-case
// This program is designed to illustrate the fallthrough behavior in switch statements.

#include <iostream>

int main()
{
    int option = 2;

    std::cout << "Option selected: " << option << "\n";

    switch (option)
    {
    case 1:
        std::cout << "Case 1: One\n";
    case 2:
        std::cout << "Case 2: Two\n";
    case 3:
        std::cout << "Case 3: Three\n";
    }

    return 0;
}
