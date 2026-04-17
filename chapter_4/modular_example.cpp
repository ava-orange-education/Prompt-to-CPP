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

// modular_example.cpp
// Demonstrates modular decomposition using separate functions.

#include <iostream>

// Gets user input
void getInput(int &value)
{
    std::cout << "Enter a positive integer: ";
    std::cin >> value;
}

// Validates the input
bool validateInput(int value)
{
    return value > 0;
}

// Processes the input (e.g., doubles the value)
int processValue(int value)
{
    return value * 2;
}

// Displays the result
void displayResult(int result)
{
    std::cout << "Processed result: " << result << "\n";
}

int main()
{
    int input;
    getInput(input);

    if (!validateInput(input))
    {
        std::cout << "Invalid input. Please enter a positive integer." << "\n";
        return 1;
    }

    int result = processValue(input);
    displayResult(result);

    return 0;
}
