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
// unit_converter_with_recursive.cpp
// This program provides a menu for converting between different units.
#include <iostream>

// Function declarations for unit conversions
double kmToMiles(double km)
{
    return km * 0.621371;
}

double milesToKm(double miles)
{
    return miles * 1.60934;
}

double celsiusToFahrenheit(double celsius)
{
    return (celsius * 9.0 / 5.0) + 32;
}

double fahrenheitToCelsius(double fahrenheit)
{
    return (fahrenheit - 32) * 5.0 / 9.0;
}

void displayMenu()
{
    std::cout << "\nUnit Converter Menu:\n";
    std::cout << "1. Kilometers to Miles\n";
    std::cout << "2. Miles to Kilometers\n";
    std::cout << "3. Celsius to Fahrenheit\n";
    std::cout << "4. Fahrenheit to Celsius\n";
    std::cout << "5. Exit\n";
    std::cout << "Enter your choice (1-5): ";
}

int main()
{
    int choice;
    double value;

    while (true)
    {
        displayMenu();
        std::cin >> choice;

        // Check for valid menu choice
        if (choice == 5)
        {
            std::cout << "Exiting program.\n";
            break;
        }
        if (choice < 1 || choice > 5)
        {
            std::cout << "Invalid choice. Please select 1-5.\n";
            continue;
        }

        // Get value to convert
        std::cout << "Enter the value to convert: ";
        std::cin >> value;

        // Validate input
        if (std::cin.fail())
        {
            std::cout << "Invalid input. Please enter a number.\n";
            std::cin.clear();             // Clear error state
            std::cin.ignore(10000, '\n'); // Discard invalid input
            continue;
        }

        // Perform conversion based on choice
        switch (choice)
        {
        case 1:
            std::cout << value << " km = " << kmToMiles(value) << " miles\n";
            break;
        case 2:
            std::cout << value << " miles = " << milesToKm(value) << " km\n";
            break;
        case 3:
            std::cout << value << " Celsius = " << celsiusToFahrenheit(value) << " Fahrenheit\n";
            break;
        case 4:
            std::cout << value << " Fahrenheit = " << fahrenheitToCelsius(value) << " Celsius\n";
            break;
        }
    }

    return 0;
}