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

// out_of_bounds_demo.cpp
// Demonstrates unsafe and safe element access in arrays
#include <array>
#include <iostream>

int main()
{
    std::array<int, 3> data = {100, 200, 300};

    std::cout << "Using operator[] (no bounds check):\n";
    std::cout << "data[1] = " << data[1] << '\n';
    // std::cout << "data[5] = " << data[5] << '\n'; // Uncommenting this may crash or show garbage

    std::cout << "\nUsing .at() (with bounds check):\n";
    try
    {
        std::cout << "data.at(1) = " << data.at(1) << '\n';
        std::cout << "data.at(5) = " << data.at(5) << '\n'; // This throws std::out_of_range
    }
    catch (const std::out_of_range &e)
    {
        std::cout << "Caught exception: " << e.what() << '\n';
    }

    return 0;
}
