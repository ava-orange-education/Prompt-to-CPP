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
// File: lambda_example.cpp
// Purpose: Demonstrate a simple lambda that checks if a sensor reading exceeds a threshold.

#include <iostream>

int main()
{
    double threshold = 25.0;

    // Define a lambda that checks if a sensor reading exceeds the threshold
    auto isHighTemp = [threshold](double value) -> bool { return value > threshold; };

    // Simulated sensor readings
    double readings[] = { 22.5, 25.1, 24.9, 26.3 };

    for (double reading : readings)
    {
        if (isHighTemp(reading))
            std::cout << "Reading " << reading << "°C exceeds the threshold of " << threshold << "°C\n";
        else
            std::cout << "Reading " << reading << "°C is within safe limits.\n";
    }

    return 0;
}
