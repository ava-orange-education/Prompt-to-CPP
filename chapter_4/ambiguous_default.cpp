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

// ambiguous_default.cpp
// Demonstrates default argument mixed with overloading causes ambiguity in C++.
#include <iostream>
void print(int a, int b = 10)
{
    std::cout << "Function with (int, int) called\n";
}

void print(int a)
{
    std::cout << "Function with (int) called\n";
}

int main()
{
    print(10); // ambiguous call, could be print(int) or print(int, int)
    print(5, 3);
    return 0;
}