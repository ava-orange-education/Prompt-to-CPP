/**
 * @file    temperature_check.cpp
 * @author  Vivek Bhadra
 *
 * @brief
 * Checks whether a user-entered temperature is above a specified threshold.
 *
 * @license
 * This file is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation; either version 3 of the License, or (at your
 * option) any later version.
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 */

// temperature_check.cpp
// This program checks if the entered temperature is above 30 degrees Celsius.
#include <iostream>
int main()
{
    int temperature;
    std::cout << "Enter temperature (°C): ";
    if(!(std::cin >> temperature))
    {
        std::cerr << "Invalid input. Please enter an integer value.\n";
        return 1; // Exit with error code
    }
    if (temperature > 30)
    {
        std::cout << "It's a hot day!\n";
    }
    return 0;
}