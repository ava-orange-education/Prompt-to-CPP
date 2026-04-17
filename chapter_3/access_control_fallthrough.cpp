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
// access_control_fallthrough.cpp
// This program demonstrates the use of fallthrough in switch statements
// to manage access control based on user roles.
#include <iostream>

int main()
{
    int role;
    std::cout << "Select role (1 = Viewer, 2 = Editor, 3 = Admin): ";
    std::cin >> role;

    std::cout << "Permissions granted:\n";

    switch (role)
    {
    case 3:
        std::cout << "- Access Admin Tools\n";
        // Fall-through intended to include Editor and Viewer rights
    case 2:
        std::cout << "- Edit Content\n";
        // Fall-through intended to include Viewer rights
    case 1:
        std::cout << "- View Content\n";
        break;
    default:
        std::cout << "Invalid role selected.\n";
    }

    return 0;
}