/**
 * @file    addition_no_function.cpp
 * @author  Vivek Bhadra
 *
 * @brief
 * Adds two integer values directly in main and prints the result without
 * using a separate function.
 *
 * @license
 * This file is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation; either version 3 of the License, or (at your
 * option) any later version.
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 */

// addition_no_function.cpp
// This program adds two integers without using a function and prints the result.

#include <iostream>

int main()
{
    const int firstNum = 5, secondNum = 3;
    int result = firstNum + secondNum;
    std::cout << "Sum is: " << result << "\n";
    return 0;
}
