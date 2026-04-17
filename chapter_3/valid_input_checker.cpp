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
// valid_input_checker.cpp
// This program checks if the user input is a positive number
// If the input is invalid, it prompts the user to enter a valid number
#include <iostream>

int main()
{
    int number;
    std::cout << "Enter a positive number: ";
    std::cin >> number;

    while (number <= 0)
    {
        std::cout << "Invalid! Enter a positive number: ";
        if (!(std::cin >> number))
        {
            std::cout << "Not a number! Stopping.\n";
            std::cin.clear();
            std::cin.ignore(10000, '\n');
            return 1;
        }
    }

    std::cout << "You entered: " << number << "\n";
    return 0;
}