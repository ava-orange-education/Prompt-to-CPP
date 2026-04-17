/**
 * @file    syntax_error_missing_semicolon.cpp
 * @author  Vivek Bhadra
 *
 * @brief
 * Demonstrates a compile-time syntax error caused by a missing semicolon.
 *
 * @license
 * This file is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation; either version 3 of the License, or (at your
 * option) any later version.
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 */

// syntax_error_missing_semicolon.cpp
#include <iostream>
int main()
{
    std::cout << "Hello" // Missing semicolon
        return 0;
}