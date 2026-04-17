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
// buggy_factorial.cpp
// Bug: off-by-one error in factorial loop
// This code is intended to be used for testing static analysis tools.

#include <iostream>

unsigned long factorial(int n)
{
    unsigned long result = 1;
    for (int i = 1; i < n; ++i) // BUG: should be i <= n
    {
        result *= i;
    }
    return result;
}

int main()
{
    int num = 5;
    std::cout << "Factorial of " << num << " = " << factorial(num) << "\n";
    // Expected: 120, but prints 24
    return 0;
}