/**
 * @file    file1.cpp
 * @author  Vivek Bhadra
 *
 * @brief
 * Defines a global variable and a function that accesses it.
 *
 * @license
 * This file is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation; either version 3 of the License, or (at your
 * option) any later version.
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 */

// file1.cpp
#include <iostream>

int sharedCount = 42; // Definition

void showSharedCount()
{
    std::cout << "Shared Count: " << sharedCount << "\n";
}