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

// fixed_loop_counter.cpp
// This program demonstrates a fixed loop counter that prints numbers from 0 to 4
// It uses a while loop with a fixed condition to ensure it runs exactly 5 times
#include <iostream>

int main()
{
    int i = 0;
    while (i < 5)
    {
        std::cout << i << " ";
        i++; // Increment i to eventually make i < 5 false
    }
    std::cout << "\n";
    return 0;
}