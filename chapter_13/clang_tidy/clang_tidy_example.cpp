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
// clang_tidy_example.cpp
// This program contains a subtle issue detectable by clang-tidy.
// It is intended for static analysis using clang-tidy.

#include <iostream>

int add(int a, int b)
{
    return a + b;
}

int main()
{
    double value = 42.7;

    int truncated = value; // implicit narrowing conversion

    int sum = add(truncated, 10);
    std::cout << "Sum: " << sum << "\n";

    return 0;
}
