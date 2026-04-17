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

// usage_of_at_method.cpp
// This program demonstrates the use of the at() method in std::array
// to safely access elements and handle out-of-bounds access.
#include <array>
#include <iostream>

int main()
{
    std::array<int, 3> data = {10, 20, 30};

    try
    {
        std::cout << "Accessing data.at(5): ";
        std::cout << data.at(5) << '\n'; // Throws std::out_of_range
    }
    catch (const std::out_of_range &e)
    {
        std::cout << "Caught exception: " << e.what() << '\n';
    }

    return 0;
}
