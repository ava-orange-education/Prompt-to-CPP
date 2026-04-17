/**
 * @file    temperature_range_classifier.cpp
 * @author  Vivek Bhadra
 *
 * @brief
 * Classifies a user-entered temperature into predefined ranges using
 * conditional statements.
 *
 * @license
 * This file is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation; either version 3 of the License, or (at your
 * option) any later version.
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 */

// temperature_range_classifier.cpp
// This program classifies the temperature into different ranges.
#include <iostream>

int main()
{
    int temperature;
    std::cout << "Enter temperature (°C): ";
    std::cin >> temperature;

    if (temperature > 30)
    {
        std::cout << "Hot";
    }
    else if (temperature >= 20)
    {
        std::cout << "Warm";
    }
    else if (temperature > 10)
    {
        std::cout << "Cool";
    }
    else if (temperature >= 4)
    {
        std::cout << "Cold";
    }
    else
    {
        std::cout << "Too cold!";
    }

    return 0;
}