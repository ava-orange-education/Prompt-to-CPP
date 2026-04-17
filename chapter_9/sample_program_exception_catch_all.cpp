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
// sample_program_exception_catch_all.cpp
// A simple C++ program demonstrating exception handling with multiple
// catch blocks including a catch-all.
#include <iostream>
#include <stdexcept>

void performOperation(int value)
{
    if (value < 0)
    {
        throw std::invalid_argument("Negative values are not allowed");
    }
    if (value == 0)
    {
        throw std::runtime_error("Value must not be zero");
    }
    if (value > 100)
    {
        throw "Value exceeds maximum limit"; // raw string thrown
    }

    std::cout << "Operation completed on value: " << value << "\n";
}

int main()
{
    try
    {
        performOperation(200);
    }
    catch (const std::invalid_argument &error)
    {
        std::cout << "Invalid argument: " << error.what() << "\n";
    }
    catch (const std::runtime_error &error)
    {
        std::cout << "Runtime error: " << error.what() << "\n";
    }
    catch (...)
    {
        std::cout << "An unknown exception occurred.\n";
    }
}
