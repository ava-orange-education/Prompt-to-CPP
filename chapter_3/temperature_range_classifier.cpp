/*
 * Copyright (C) 2026
 * Author: Vivek Bhadra
 * 
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program. If not, see <https://www.gnu.org/licenses/>.
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