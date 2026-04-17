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

// function_addition.cpp
// This program defines a function to add two integers and prints the result.
#include <iostream>

// This is a function that adds two integers and returns the result
int add(const int a, const int b)
{
    return a + b;
}

int main()
{
    const int result = add(5, 3); // Function is invoked here
    std::cout << "Sum is: " << result << "\n";
    return 0;
}
