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

// vector_capacity_methods_demo.cpp
// This program demonstrates the use of vector capacity methods in C++.
// It shows how to reserve memory, add elements, and resize a vector.
// It also illustrates the difference between size and capacity.
#include <iostream>
#include <vector>

int main()
{
    std::vector<int> numbers;

    std::cout << "Initial state:\n";
    std::cout << "Size: " << numbers.size() << "\n";
    std::cout << "Capacity: " << numbers.capacity() << "\n";

    // Pre-allocate memory for at least 10 elements
    numbers.reserve(10);
    std::cout << "\nAfter reserve(10):\n";
    std::cout << "Size: " << numbers.size() << "\n";
    std::cout << "Capacity: " << numbers.capacity() << " (memory reserved)\n";

    // Add 5 elements to the vector
    for (int i = 1; i <= 5; ++i)
    {
        numbers.push_back(i * 10); // 10, 20, 30, 40, 50
    }

    std::cout << "\nAfter adding 5 elements:\n";
    std::cout << "Size: " << numbers.size() << "\n";
    std::cout << "Capacity: " << numbers.capacity() << "\n";

    std::cout << "Contents: ";
    for (int val : numbers)
    {
        std::cout << val << " ";
    }
    std::cout << "\n";

    // Resize to 8 elements (adds default-initialized values)
    numbers.resize(8);
    std::cout << "\nAfter resize(8):\n";
    std::cout << "Size: " << numbers.size() << " (3 new elements added)\n";
    std::cout << "Capacity: " << numbers.capacity() << "\n";

    std::cout << "Contents: ";
    for (int val : numbers)
    {
        std::cout << val << " ";
    }
    std::cout << "\n";

    // Resize down to 3 elements (removes extra values)
    numbers.resize(3);
    std::cout << "\nAfter resize(3):\n";
    std::cout << "Size: " << numbers.size() << " (remaining elements kept)\n";
    std::cout << "Capacity: " << numbers.capacity() << " (unchanged)\n";

    std::cout << "Contents: ";
    for (int val : numbers)
    {
        std::cout << val << " ";
    }
    std::cout << "\n";

    return 0;
}
