/**
 * @file    do_while_basic_example.cpp
 * @author  Vivek Bhadra
 *
 * @brief
 * Demonstrates a do-while loop that executes at least once before
 * checking the loop condition.
 *
 * @license
 * This file is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation; either version 3 of the License, or (at your
 * option) any later version.
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 */

// do_while_basic_example.cpp
// This program demonstrates how a do...while loop executes at least once

#include <iostream>

int main()
{
    int number;

    do
    {
        std::cout << "Enter a number greater than 10: ";
        std::cin >> number;
    } while (number <= 10);

    std::cout << "Thank you! You entered: " << number << "\n";
    return 0;
}