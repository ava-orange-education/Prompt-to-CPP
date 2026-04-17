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

// menu_retry_system.cpp
// This program implements a retry system for a menu selection
// It allows the user to retry entering a valid choice until they choose to exit
#include <iostream>

int main()
{
    int choice;
    do
    {
        std::cout << "Menu: 1) Play 2) Exit\nEnter choice: ";
        if (!(std::cin >> choice))
        {
            std::cout << "Invalid input! Please enter a number.\n";
            std::cin.clear();
            std::cin.ignore(10000, '\n');
            continue;
        }
        if (choice == 2)
        {
            std::cout << "Exiting...\n";
            return 0;
        }
        if (choice == 1)
        {
            std::cout << "Starting game...\n";
        }
        else
        {
            std::cout << "Invalid choice! Try again.\n";
        }
    } while (choice != 1);
    return 0;
}