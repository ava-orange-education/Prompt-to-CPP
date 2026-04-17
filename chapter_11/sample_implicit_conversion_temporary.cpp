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
// sample_implicit_conversion_temporary.cpp
// Temporary created by implicit type conversion
// This example shows how an integer literal is implicitly converted to a double temporary

#include <iostream>

void printDouble(double value)
{
    std::cout << value << '\n';
}

int main()
{
    printDouble(5); // Integer literal 5 is implicitly converted to a temporary double

    return 0;
}
