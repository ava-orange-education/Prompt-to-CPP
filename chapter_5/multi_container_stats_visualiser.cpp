/**
 * @file    multi_container_stats_visualiser.cpp
 * @author  Vivek Bhadra
 *
 * @brief
 * Compares C-style arrays, std::array, and std::vector by computing
 * basic statistics and visualising element addresses for each container.
 *
 * @license
 * This file is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation; either version 3 of the License, or (at your
 * option) any later version.
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 */

// Generate a C++ program that defines a C-style array, a std::array, and a std::vector,
// and prints min, max, sum, average, size, and simulated memory addresses for each.
// Use .at() for safe access where available. Simulate address layout for all containers.
// multi_container_stats_visualiser.cpp
#include <algorithm>
#include <array>
#include <iostream>
#include <numeric>
#include <vector>

template <typename T, std::size_t N> void printArrayInfo(const T (&arr)[N])
{
    std::cout << "C-style array:\n";
    std::cout << "Size: " << N << "\n";
    std::cout << "Min: " << *std::min_element(arr, arr + N) << "\n";
    std::cout << "Max: " << *std::max_element(arr, arr + N) << "\n";
    std::cout << "Sum: " << std::accumulate(arr, arr + N, 0) << "\n";
    std::cout << "Average: " << static_cast<double>(std::accumulate(arr, arr + N, 0)) / N << "\n";
    for (std::size_t i = 0; i < N; ++i)
    {
        std::cout << "Address of element " << i << ": " << &arr[i] << "\n";
    }
}

template <typename T, std::size_t N> void printArrayInfo(const std::array<T, N> &arr)
{
    std::cout << "std::array:\n";
    std::cout << "Size: " << arr.size() << "\n";
    std::cout << "Min: " << *std::min_element(arr.begin(), arr.end()) << "\n";
    std::cout << "Max: " << *std::max_element(arr.begin(), arr.end()) << "\n";
    std::cout << "Sum: " << std::accumulate(arr.begin(), arr.end(), 0) << "\n";
    std::cout << "Average: " << static_cast<double>(std::accumulate(arr.begin(), arr.end(), 0)) / N << "\n";
    for (std::size_t i = 0; i < N; ++i)
    {
        std::cout << "Address of element " << i << ": " << &arr.at(i) << "\n";
    }
}

template <typename T> void printArrayInfo(const std::vector<T> &vec)
{
    std::cout << "std::vector:\n";
    std::cout << "Size: " << vec.size() << "\n";
    if (!vec.empty())
    {
        std::cout << "Min: " << *std::min_element(vec.begin(), vec.end()) << "\n";
        std::cout << "Max: " << *std::max_element(vec.begin(), vec.end()) << "\n";
        std::cout << "Sum: " << std::accumulate(vec.begin(), vec.end(), 0) << "\n";
        std::cout << "Average: " << static_cast<double>(std::accumulate(vec.begin(), vec.end(), 0)) / vec.size()
                  << "\n";
    }
    else
    {
        std::cout << "Min, Max, Sum, and Average: N/A (vector is empty)\n";
    }
    for (std::size_t i = 0; i < vec.size(); ++i)
    {
        std::cout << "Address of element " << i << ": " << &vec.at(i) << "\n";
    }
}

int main()
{
    int cArray[] = {1, 2, 3, 4, 5};
    std::array<int, 5> stdArray = {6, 7, 8, 9, 10};
    std::vector<int> stdVector = {11, 12, 13, 14, 15};

    printArrayInfo(cArray);
    printArrayInfo(stdArray);
    printArrayInfo(stdVector);

    return 0;
}
// This program demonstrates the use of C-style arrays, std::array, and std::vector in C++17.
// It calculates and prints various statistics and simulated memory addresses for each container type.
// The program uses safe access methods like .at() for std::array and std::vector where applicable.
// It also ensures that the code is compatible with C++17 standards.