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
// sample_program_terminate_destructor.cpp
// Demonstrate termination when a destructor throws during stack unwinding.

#include <exception>
#include <iostream>
#include <stdexcept>

void onTerminate() noexcept
{
    std::cout << "[terminate] Exception thrown in destructor during unwinding.\n";
}

struct Bomb
{
    ~Bomb() noexcept // Destructors are implicitly noexcept(true) unless specified otherwise.
    {
        // Throwing here during stack unwinding will trigger std::terminate.
        throw std::runtime_error("boom in destructor");
    }
};

void do_work()
{
    Bomb b; // Will be destroyed during unwinding
    throw std::runtime_error("initial failure");
}

int main()
{
    std::set_terminate(onTerminate);

    try
    {
        do_work();
    }
    catch (const std::exception &e)
    {
        // We never reach this handler: termination occurs first.
        std::cout << "Caught in main: " << e.what() << '\n';
    }

    return 0;
}
