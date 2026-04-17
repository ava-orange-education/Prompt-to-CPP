/**
 * @file    linking_error_demo.cpp
 * @author  Vivek Bhadra
 *
 * @brief
 * Demonstrates a linker error caused by a declared but undefined function.
 *
 * @license
 * This file is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation; either version 3 of the License, or (at your
 * option) any later version.
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 */

// linking_error_demo.cpp
#include <iostream>
extern void undefined_function(); // Declared, not defined
int main()
{
    undefined_function();
    return 0;
}