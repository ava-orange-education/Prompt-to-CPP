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

// do_while_basic_example.cpp
// This program demonstrates how a do...while loop executes at least once

#include <iostream>

int main()
{
    int number;

    do
    {
        std::cout << "Enter a number greater than 10: ";
        std::cin >> number;
    } while (number <= 10);

    std::cout << "Thank you! You entered: " << number << "\n";
    return 0;
}