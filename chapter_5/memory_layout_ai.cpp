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

// Generate a C++ program that explains how a C++ array of 5 integers is stored in memory with hypothetical addresses
// memory_layout_ai.cpp
#include <iomanip>
#include <iostream>

int main()
{
    // Hypothetical memory addresses for the array elements
    const int baseAddress = 0x1000;      // Base address of the array in memory
    const int elementSize = sizeof(int); // Size of each integer in bytes

    // Array declaration
    int arr[5] = {10, 20, 30, 40, 50};

    std::cout << "Memory layout of an array of 5 integers:\n";
    std::cout << "---------------------------------------\n";
    std::cout << std::setw(10) << "Address" << std::setw(10) << "Value" << std::setw(10) << "Index"
              << "\n";
    std::cout << "---------------------------------------\n";

    // Displaying the memory layout
    for (int i = 0; i < 5; ++i)
    {
        int address = baseAddress + i * elementSize; // Calculate the address of each element
        std::cout << std::setw(10) << std::hex << address << std::setw(10) << std::dec << arr[i] << std::setw(10) << i
                  << "\n";
    }

    std::cout << "---------------------------------------\n";
    std::cout << "Note: The addresses are hypothetical and may vary in actual memory layout.\n";

    return 0;
}
// Compile with C++17 standard: g++ -std=c++17 memory_layout_ai.cpp -o memory_layout_ai
// Run the program: ./memory_layout_ai
// This program illustrates how an array of integers is stored in memory, showing the addresses, values, and indices.