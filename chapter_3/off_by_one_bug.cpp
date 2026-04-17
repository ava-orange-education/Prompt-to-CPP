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

// off_by_one_bug.cpp
// This program prints numbers from 0 to 5, but it has an off-by-one error
// The loop condition should be i < 5 instead of i <= 5 to avoid printing 5
#include <iostream>

int main()
{
    for (int i = 0; i <= 5; ++i)
    {
        std::cout << i << " ";
    }
    std::cout << "\n";
    return 0;
}