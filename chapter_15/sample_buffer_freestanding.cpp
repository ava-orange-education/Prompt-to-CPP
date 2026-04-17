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
// sample_buffer_freestanding.cpp
//  A freestanding-compliant implementation.
// This version respects environment constraints by avoiding 
// heap-based containers and utilizing an in-place insertion sort.

#include <cstddef>

void sortSensorReadings(double* buffer, std::size_t count)
{
    if (buffer == nullptr || count < 2)
    {
        return;
    }

    // Insertion sort: In-place, O(1) auxiliary space, no heap allocation.
    for (std::size_t i = 1; i < count; ++i)
    {
        const double key = buffer[i];
        std::size_t j = i;

        while (j > 0 && buffer[j - 1] > key)
        {
            buffer[j] = buffer[j - 1];
            --j;
        }

        buffer[j] = key;
    }
}

int main()
{
    // Allocation occurs on the stack, satisfying the zero-heap requirement.
    double sensorReadings[8] = {23.4, 19.8, 25.1, 18.6, 22.0, 21.9, 24.3, 20.5};

    sortSensorReadings(sensorReadings, 8);

    return 0;
}