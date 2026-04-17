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
// factorial.cpp
// Demonstrates recursion in C++ to compute factorial.
#include <iostream>

// Function to calculate factorial recursively
unsigned long long factorial(unsigned long long n)
{
    if (n <= 1)
        return 1;                // Base case: factorial of 0 or 1 is 1
    return n * factorial(n - 1); // Recursive case: n! = n * (n-1)!
}

int main()
{
    int n;
    std::cout << "Enter a non-negative integer to compute its factorial: ";
    std::cin >> n;

    // Basic input validation
    if (n < 0)
    {
        std::cout << "Error: Factorial is not defined for negative numbers." << "\n";
        return 1;
    }

    unsigned long long result = factorial(static_cast<unsigned long long>(n));
    std::cout << "Factorial of " << n << " is " << result << "\n";

    return 0;
}