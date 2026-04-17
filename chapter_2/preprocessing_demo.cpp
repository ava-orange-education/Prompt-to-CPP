/**
 * @file    preprocessing_demo.cpp
 * @author  Vivek Bhadra
 *
 * @brief
 * Demonstrates the use of a preprocessor macro defined using #define.
 *
 * @license
 * This file is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation; either version 3 of the License, or (at your
 * option) any later version.
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 */

 // preprocessing_demo.cpp
#include <iostream>
#define MAX 100
int main()
{
    std::cout << "Max: " << MAX << "\n";
    return 0;
}