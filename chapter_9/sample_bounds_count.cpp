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
// sample_bounds_count.cpp
// Demonstrates using std::lower_bound and std::upper_bound to count occurrences of
// a key in a sorted vector
#include <algorithm>
#include <iostream>
#include <vector>

int main()
{
    std::vector<int> v{ 10, 20, 20, 20, 30, 40 }; // sorted vector
    int key = 20;

    auto lb = std::lower_bound(v.begin(), v.end(), key); // first element >= key
    auto ub = std::upper_bound(v.begin(), v.end(), key); // first element > key

    std::cout << "Count: " << (ub - lb) << '\n'; // prints 3

    return 0;
}