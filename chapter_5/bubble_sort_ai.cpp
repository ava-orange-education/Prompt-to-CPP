/**
 * @file    bubble_sort_ai.cpp
 * @author  Vivek Bhadra
 *
 * @brief
 * Demonstrates the bubble sort algorithm using std::array to sort
 * a fixed-size collection of integers in ascending order.
 *
 * @license
 * This file is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation; either version 3 of the License, or (at your
 * option) any later version.
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
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
