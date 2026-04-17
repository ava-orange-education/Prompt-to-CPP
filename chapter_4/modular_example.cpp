/**
 * @file    modular_example.cpp
 * @author  Vivek Bhadra
 *
 * @brief
 * Demonstrates modular program design by decomposing functionality
 * into separate input, validation, processing, and output functions.
 *
 * @license
 * This file is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation; either version 3 of the License, or (at your
 * option) any later version.
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
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
