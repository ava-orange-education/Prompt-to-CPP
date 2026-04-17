/**
 * @file    out_of_bound_array_ai.cpp
 * @author  Vivek Bhadra
 *
 * @brief
 * Demonstrates undefined behaviour caused by accessing an array element
 * outside its valid bounds.
 *
 * @license
 * This file is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation; either version 3 of the License, or (at your
 * option) any later version.
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 */

// out_of_bound_array_ai.cpp
#include <iostream>

int main()
{
    int numbers[3] = {1, 2, 3};
    std::cout << "Accessing out of bound element:" << numbers[5] << "\n"; // This will cause undefined behavior
    return 0;
}