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

// default_initialisation_demo.cpp
// Demonstrates default initialisation of global vs local arrays

#include <iostream>

int globalArray[3]; // Default-initialised to zero (static storage)

int main()
{
    int localArray[3]; // Not initialised (automatic storage)

    std::cout << "Global array (default-initialised):\n";
    for (int i = 0; i < 3; ++i)
    {
        std::cout << "  globalArray[" << i << "] = " << globalArray[i] << "\n";
    }

    std::cout << "\nLocal array (uninitialised, contains garbage):\n";
    for (int i = 0; i < 3; ++i)
    {
        std::cout << "  localArray[" << i << "] = " << localArray[i] << "\n";
    }

    return 0;
}
