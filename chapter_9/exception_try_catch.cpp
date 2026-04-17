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
// exception_try_catch.cpp
// A simple C++ program demonstrating exception handling with try and catch blocks.

#include <fstream>
#include <iostream>
#include <stdexcept>

void readFile(const std::string &fileName)
{
    std::ifstream file(fileName);

    if (!file)
    {
        // If the file cannot be opened, signal this with an exception
        throw std::runtime_error("Failed to open file: " + fileName);
    }

    std::cout << "File opened successfully.\n";
    // Simulate file processing (e.g., reading content)
}

int main()
{
    try
    {
        // This file does not exist, so an exception will be thrown
        readFile("non_existent_file.txt");
    }
    catch (const std::exception &e)
    {
        std::cout << "Exception caught: " << e.what() << "\n";
    }

    std::cout << "Program continues after handling the exception safely.\n";
    return 0;
}
