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