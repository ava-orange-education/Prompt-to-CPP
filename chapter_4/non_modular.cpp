/**
 * @file    non_modular.cpp
 * @author  Vivek Bhadra
 *
 * @brief
 * Demonstrates a monolithic program structure without modular
 * decomposition into separate functions.
 *
 * @license
 * This file is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation; either version 3 of the License, or (at your
 * option) any later version.
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 */

// non_modular.cpp
// Demonstrates a monolithic function with no logical separation.

#include <iostream>

int main()
{
    int input;
    std::cout << "Enter a positive integer: ";
    std::cin >> input;

    if (input <= 0)
    {
        std::cout << "Invalid input. Please enter a positive integer." << "\n";
        return 1;
    }

    int result = input * 2;
    std::cout << "Processed result: " << result << "\n";

    return 0;
}
