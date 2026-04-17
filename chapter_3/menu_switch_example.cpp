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

// menu_switch_example.cpp
// This program demonstrates the use of a switch statement to handle menu options.
#include <iostream>

int main()
{
    int choice;
    std::cout << "Menu: 1) Play  2) Settings  3) Exit\nEnter choice: ";
    std::cin >> choice;

    switch (choice)
    {
    case 1:
        std::cout << "Starting game...\n";
        break;
    case 2:
        std::cout << "Opening settings...\n";
        break;
    case 3:
        std::cout << "Exiting...\n";
        break;
    default:
        std::cout << "Invalid choice!\n";
    }

    return 0;
}
