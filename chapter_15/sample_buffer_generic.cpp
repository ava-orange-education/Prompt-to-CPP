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
// sample_buffer_generic.cpp
// This approach assumes a hosted environment.
// Demonstrates a hidden risk of using dynamic memory allocation in generic code
#include <iostream>
#include <vector>
#include <algorithm>

void sortSensorReadings(std::vector<double>& readings)
{
    // Hidden risk: std::vector allocates on the heap.
    // This will fail in environments without an allocator (e.g., bare-metal).
    std::sort(readings.begin(), readings.end());
}

int main()
{
    std::vector<double> data = {45.2, 12.5, 88.7, 32.1};
    sortSensorReadings(data);

    for (const auto& val : data) {
        std::cout << val << " ";
    }
    std::cout << "\n";
    
    return 0;
}