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
// print_type_sizes.cpp

#include <iostream>
int main()
{
    std::cout << "Size of char: " << sizeof(char) << " bytes"
              << "\n";
    std::cout << "Size of short: " << sizeof(short) << " bytes"
              << "\n";
    std::cout << "Size of int: " << sizeof(int) << " bytes"
              << "\n";
    std::cout << "Size of long: " << sizeof(long) << " bytes"
              << "\n";
    std::cout << "Size of long long: " << sizeof(long long) << " bytes"
              << "\n";
    std::cout << "Size of float: " << sizeof(float) << " bytes"
              << "\n";
    std::cout << "Size of double: " << sizeof(double) << " bytes"
              << "\n";
    std::cout << "Size of long double: " << sizeof(long double) << " bytes"
              << "\n";
    std::cout << "Size of bool: " << sizeof(bool) << " bytes"
              << "\n";

    return 0;
}