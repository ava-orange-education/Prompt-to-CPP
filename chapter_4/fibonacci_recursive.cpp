/**
 * @file    fibonacci_recursive.cpp
 * @author  Vivek Bhadra
 *
 * @brief
 * Demonstrates recursive computation of Fibonacci numbers and helps
 * trace recursive execution for understanding and debugging.
 *
 * @license
 * This file is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation; either version 3 of the License, or (at your
 * option) any later version.
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
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
