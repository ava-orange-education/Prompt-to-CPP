/**
 * @file    number_classification.cpp
 * @author  Vivek Bhadra
 *
 * @brief
 * Classifies a user-provided number as negative, zero, or positive
 * using nested conditional statements.
 *
 * @license
 * This file is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation; either version 3 of the License, or (at your
 * option) any later version.
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 */

// number_classification.cpp
// This program classifies a number as negative, zero, or positive
#include <iostream>

#include <iostream>

int main()
{
    int number;
    std::cout << "Enter a number: ";
    std::cin >> number;

    if (number >= 0)
    {
        if (number == 0)
        {
            std::cout << "The number is zero.\n";
        }
        else
        {
            std::cout << "The number is positive.\n";
        }
    }
    else
    {
        std::cout << "The number is negative.\n";
    }

    return 0;
}