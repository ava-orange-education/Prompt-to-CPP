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
// sample_program_terminate_noexcept.cpp
// A simple C++ program demonstrating the use of std::terminate
// and noexcept functions.
// When a noexcept function throws an exception, std::terminate is called.

#include <exception> // std::set_terminate, std::terminate
#include <iostream>
#include <stdexcept>

void onTerminate() noexcept
{
    std::cout << "[terminate] Unhandled exception or noexcept violation detected.\n";
    // The program will end immediately after this handler returns.
}

void must_not_throw() noexcept
{
    // Any exception leaving a noexcept function triggers std::terminate.
    throw std::runtime_error("unexpected error in noexcept function");
}

int main()
{
    std::set_terminate(onTerminate);

    // Do NOT wrap with try/catch: we want to see terminate in action.
    must_not_throw();

    // Unreachable.
    std::cout << "This line will never print.\n";
    return 0;
}
