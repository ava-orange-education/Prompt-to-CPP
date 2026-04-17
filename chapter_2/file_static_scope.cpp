/**
 * @file    file_static_scope.cpp
 * @author  Vivek Bhadra
 *
 * @brief
 * Demonstrates file scope and internal linkage using a static variable.
 *
 * @license
 * This file is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation; either version 3 of the License, or (at your
 * option) any later version.
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 */

// file_static_scope.cpp
#include <iostream>

// This variable is only visible within this file
static int internalVar = 10;

void showInternal()
{
    std::cout << "Internal variable value: " << internalVar << "\n";
}

int main()
{
    showInternal();
    return 0;
}