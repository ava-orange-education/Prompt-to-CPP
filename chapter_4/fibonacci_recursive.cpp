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

// fibonacci_recursive.cpp
// Demonstrates recursion and helps trace execution for debugging.

#include <iostream>

// Recursive function to compute the nth Fibonacci number
unsigned long long fibonacci(int n)
{
    if (n <= 1)
        return n;                               // Base case
    return fibonacci(n - 1) + fibonacci(n - 2); // Recursive case
}

int main()
{
    int n;
    std::cout << "Enter a non-negative integer: ";
    std::cin >> n;

    if (n < 0)
    {
        std::cout << "Error: Fibonacci not defined for negative numbers." << "\n";
        return 1;
    }

    std::cout << "Fibonacci(" << n << ") = " << fibonacci(n) << "\n";
    return 0;
}
