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
// auto_generated_menu.cpp
// Create a switch menu for 3 user options with break and default
#include <iostream>
using namespace std;

int main()
{
    int choice;

    cout << "Welcome to the Menu!" << endl;
    cout << "Please select an option:" << endl;
    cout << "1. Option One" << endl;
    cout << "2. Option Two" << endl;
    cout << "3. Option Three" << endl;
    cout << "Enter your choice (1-3): ";
    cin >> choice;

    switch (choice)
    {
    case 1:
        cout << "You selected Option One." << endl;
        break;
    case 2:
        cout << "You selected Option Two." << endl;
        break;
    case 3:
        cout << "You selected Option Three." << endl;
        break;
    default:
        cout << "Invalid choice! Please select a valid option." << endl;
        break;
    }

    return 0;
}
