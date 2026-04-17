/**
 * @file    print_type_sizes.cpp
 * @author  Vivek Bhadra
 *
 * @brief
 * Prints the sizes of fundamental C++ data types using the sizeof operator.
 *
 * @license
 * This file is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation; either version 3 of the License, or (at your
 * option) any later version.
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 */

// print_type_sizes.cpp

#include <iostream>
int main()
{
    std::cout << "Size of char: " << sizeof(char) << " bytes"
              << "\n";
    std::cout << "Size of short: " << sizeof(short) << " bytes"
              << "\n";
    std::cout << "Size of int: " << sizeof(int) << " bytes"
              << "\n";
    std::cout << "Size of long: " << sizeof(long) << " bytes"
              << "\n";
    std::cout << "Size of long long: " << sizeof(long long) << " bytes"
              << "\n";
    std::cout << "Size of float: " << sizeof(float) << " bytes"
              << "\n";
    std::cout << "Size of double: " << sizeof(double) << " bytes"
              << "\n";
    std::cout << "Size of long double: " << sizeof(long double) << " bytes"
              << "\n";
    std::cout << "Size of bool: " << sizeof(bool) << " bytes"
              << "\n";

    return 0;
}