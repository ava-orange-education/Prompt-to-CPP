/**
 * @file    segfault_example.cpp
 * @author  Vivek Bhadra
 *
 * @brief
 * Demonstrates undefined behaviour caused by accessing an array element
 * outside its valid bounds, which may result in a segmentation fault.
 *
 * @license
 * This file is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation; either version 3 of the License, or (at your
 * option) any later version.
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 */

// segfault_example.cpp
// This program demonstrates a segmentation fault by accessing an out-of-bounds index in an array.
#include <iostream>

int main()
{
    int numbers[3] = {10, 20, 30};

    std::cout << "Accessing numbers[5]...\n";
    std::cout << numbers[5] << std::endl; // Undefined behaviour

    return 0;
}
