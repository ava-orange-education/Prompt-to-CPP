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

// bubble_sort_ai.cpp
// This program demonstrates the bubble sort algorithm using std::array in C++.
// It sorts an array of integers in ascending order and prints the sorted array.
#include <array>
#include <iostream>

void bubbleSort(std::array<int, 5> &arr)
{
    for (std::size_t i = 0; i < arr.size(); ++i)
    {
        for (std::size_t j = 0; j < arr.size() - i - 1; ++j)
        {
            if (arr[j] > arr[j + 1])
            {
                std::swap(arr[j], arr[j + 1]);
            }
        }
    }
}

int main()
{
    std::array<int, 5> data = {5, 3, 4, 1, 2};
    bubbleSort(data);

    for (int x : data)
    {
        std::cout << x << ' ';
    }

    return 0;
}
