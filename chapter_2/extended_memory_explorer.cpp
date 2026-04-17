/**
 * @file    extended_memory_explorer.cpp
 * @author  Vivek Bhadra
 *
 * @brief
 * Explores variable values, memory addresses, and sizes of basic C++ data types.
 *
 * @license
 * This file is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation; either version 3 of the License, or (at your
 * option) any later version.
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 */

// extended_memory_explorer.cpp
#include <iostream>
int main()
{
    int i = 42;
    double d = 3.14;
    char c = 'A';
    float f = 2.718f;
    bool b = true;
    std::cout << "Value of i: " << i << ", Address: " << &i << ", Size: " << sizeof(i) << "\n";
    std::cout << "Value of d: " << d << ", Address: " << &d << ", Size: " << sizeof(d) << "\n";
    std::cout << "Value of c: " << c << ", Address: " << (void *)&c << ", Size: " << sizeof(c) << "\n";
    std::cout << "Value of f: " << f << ", Address: " << &f << ", Size: " << sizeof(f) << "\n";
    std::cout << "Value of b: " << b << ", Address: " << &b << ", Size: " << sizeof(b) << "\n";
    return 0;
}