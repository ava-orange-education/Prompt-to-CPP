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
// sample_function_return_temporary.cpp
// Function returning an object by value creating a temporary
// This example shows how a temporary object can be used to initialize a variable.

#include <iostream>
#include <string>

std::string makeGreeting()
{
    return "Hello, World!"; // Temporary std::string constructed here
}

int main()
{
    std::string message = makeGreeting(); // Temporary initializes 'message'
    std::cout << message << '\n';

    return 0;
}
