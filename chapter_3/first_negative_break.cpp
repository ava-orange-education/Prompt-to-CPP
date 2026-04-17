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

// first_negative_break.cpp
// This program prompts the user to enter up to 5 numbers.
// If a negative number is entered
#include <iostream>
int main()
{
    int number;
    std::cout << "Enter up to 5 numbers (stop on negative):\n";
    for (int i = 0; i < 5; ++i)
    {
        std::cout << "Enter number: ";
        std::cin >> number;

        if (number < 0)
        {
            std::cout << "Negative number entered. Exiting loop.\n";
            break; // Exit the loop early
        }

        std::cout << "You entered: " << number << "\n";
    }
    return 0;
}
