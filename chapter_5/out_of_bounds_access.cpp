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

// out_of_bounds_access.cpp
// This program demonstrates out-of-bounds access on a std::array
// in C++. It shows the undefined behavior that occurs when accessing
// elements beyond the container's bounds.
#include <array>
#include <iostream>

int main()
{
    std::array<int, 3> data = {1, 2, 3};

    std::cout << "Valid access:\n";
    for (std::size_t i = 0; i < data.size(); ++i)
    {
        std::cout << "data[" << i << "] = " << data[i] << '\n';
    }

    std::cout << "\nAttempting out-of-bounds access:\n";
    int x = data[5];                        // Undefined behaviour: index 5 is out of bounds
    std::cout << "data[5] = " << x << '\n'; // This line may print garbage or crash

    return 0;
}
