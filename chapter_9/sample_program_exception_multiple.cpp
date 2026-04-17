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
// sample_program_exception_multiple.cpp
// A simple C++ program demonstrating exception handling with multiple catch blocks.
#include <iostream>
#include <stdexcept>

void validateTransaction(double amount)
{
    if (amount < 0.0)
    {
        throw std::invalid_argument("Transaction amount cannot be negative");
    }
    if (amount == 0.0)
    {
        throw std::runtime_error("Transaction amount cannot be zero");
    }
    std::cout << "Transaction of " << amount << " processed successfully.\n";
}

int main()
{
    try
    {
        validateTransaction(0.0);
    }
    catch (const std::invalid_argument &error)
    {
        std::cout << "Invalid input: " << error.what() << "\n";
    }
    catch (const std::runtime_error &error)
    {
        std::cout << "Runtime problem: " << error.what() << "\n";
    }

    return 0;
}
