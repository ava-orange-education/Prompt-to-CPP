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
// sample_transform_temperature.cpp
// Demonstrates using std::transform to convert Celsius to Fahrenheit
#include <algorithm>
#include <iostream>
#include <vector>

double toFahrenheit(double c)
{
    return (c * 9.0 / 5.0) + 32.0;
}

int main()
{
    std::vector<double> celsius{ 0.0, 10.0, 20.0, 30.0 };
    std::vector<double> fahrenheit(celsius.size());

    // Apply 'toFahrenheit' to each element in 'celsius', store results in 'fahrenheit'
    std::transform(celsius.begin(), celsius.end(), fahrenheit.begin(), toFahrenheit);

    std::cout << "Temperatures in Fahrenheit: ";
    for (double f : fahrenheit)
        std::cout << f << ' ';
}
