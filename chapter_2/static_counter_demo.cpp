/**
 * @file    static_counter_demo.cpp
 * @author  Vivek Bhadra
 *
 * @brief
 * Demonstrates a static local variable retaining its value across function calls.
 *
 * @license
 * This file is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation; either version 3 of the License, or (at your
 * option) any later version.
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 */

// static_counter_demo.cpp
#include <iostream>

// Function with a static local variable
void counter()
{
    static int count = 0; // This retains its value between calls
    count++;
    std::cout << "Counter: " << count << "\n";
}

int main()
{
    counter(); // Output: Counter: 1
    counter(); // Output: Counter: 2
    counter(); // Output: Counter: 3
    return 0;
}
