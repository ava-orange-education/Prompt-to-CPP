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

// unit_converter.cpp
// Demonstrates modular unit conversion with a menu-driven interface.
#include <iostream>
#include <limits>

// Function declarations
void displayMenu();
double kmToMiles(double km);
double milesToKm(double miles);
double celsiusToFahrenheit(double celsius);
double fahrenheitToCelsius(double fahrenheit);
void clearInputBuffer();

// Main function
// This program provides a menu for converting between different units.
int main()
{
    int choice;
    double value, result;

    while (true)
    {
        displayMenu();
        std::cout << "Enter choice (1-5): ";
        std::cin >> choice;

        if (choice == 5)
            break;

        if (choice < 1 || choice > 5)
        {
            std::cout << "Invalid choice. Try again.\n";
            clearInputBuffer();
            continue;
        }

        std::cout << "Enter value to convert: ";
        std::cin >> value;

        if (std::cin.fail())
        {
            std::cout << "Invalid input. Try again.\n";
            clearInputBuffer();
            continue;
        }

        switch (choice)
        {
        case 1:
            result = kmToMiles(value);
            std::cout << value << " km = " << result << " miles\n";
            break;
        case 2:
            result = milesToKm(value);
            std::cout << value << " miles = " << result << " km\n";
            break;
        case 3:
            result = celsiusToFahrenheit(value);
            std::cout << value << " °C = " << result << " °F\n";
            break;
        case 4:
            result = fahrenheitToCelsius(value);
            std::cout << value << " °F = " << result << " °C\n";
            break;
        default:
            std::cout << "Invalid choice. Please try again.\n";
            clearInputBuffer();
            continue;
        }
    }
    return 0;
}

void displayMenu()
{
    std::cout << "\nUnit Converter\n"
              << "1. Kilometers to Miles\n"
              << "2. Miles to Kilometers\n"
              << "3. Celsius to Fahrenheit\n"
              << "4. Fahrenheit to Celsius\n"
              << "5. Exit\n";
}

// Conversion functions
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

void clearInputBuffer()
{
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}