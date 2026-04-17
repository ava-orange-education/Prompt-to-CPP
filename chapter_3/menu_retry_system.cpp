/**
 * @file    menu_retry_system.cpp
 * @author  Vivek Bhadra
 *
 * @brief
 * Demonstrates a menu-driven retry system using a do-while loop with
 * basic input validation.
 *
 * @license
 * This file is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation; either version 3 of the License, or (at your
 * option) any later version.
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
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