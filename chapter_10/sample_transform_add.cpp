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
// sample_transform_add.cpp
// Demonstrates using std::transform to add elements of two vectors
#include <algorithm>
#include <iostream>
#include <vector>

int add(int a, int b) { return a + b; }

int main()
{
    std::vector<int> v1{ 1, 2, 3, 4 };
    std::vector<int> v2{ 10, 20, 30, 40 };
    std::vector<int> result(v1.size());

    // Add elements of v1 and v2, store in result
    std::transform(v1.begin(), v1.end(), v2.begin(), result.begin(), add);

    std::cout << "Element-wise sums: ";
    for (int n : result)
        std::cout << n << ' ';
}
