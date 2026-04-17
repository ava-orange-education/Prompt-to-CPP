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
// pointer_arithmetic.cpp
// Demonstrates pointer arithmetic in C++

#include <iostream>

int main()
{
    int arr[3] = {10, 20, 30};
    int *p = arr; // arr decays to pointer to first element

    std::cout << *p << '\n';       // 10
    std::cout << *(p + 1) << '\n'; // 20
    std::cout << *(p + 2) << '\n'; // 30

    return 0;
}
