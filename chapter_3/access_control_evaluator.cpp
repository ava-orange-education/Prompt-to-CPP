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
// access_control_evaluator.cpp
// This program checks whether a user is allowed access based on age and ID status.

#include <iostream>

int main()
{
    int age;
    bool hasID;

    std::cout << "Enter your age: ";
    if(!(std::cin >> age))
    {
        std::cerr << "Invalid input. Please enter an integer value for age.\n";
        return 1; // Exit with error code
    }

    std::cout << "Do you have an ID? (1 = yes, 0 = no): ";
    if(!(std::cin >> hasID))
    {
        std::cerr << "Invalid input. Please enter a boolean value for ID status.\n";
        return 1; // Exit with error code
    }

    // Access is granted if the person is 18+ and has ID, or if the person is a senior (60+)
    if ((age >= 18 && hasID) || age >= 60)
    {
        std::cout << "Access granted.\n";
    }
    else
    {
        std::cout << "Access denied.\n";
    }

    return 0;
}
