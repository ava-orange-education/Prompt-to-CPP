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
// sample_find_if_even.cpp
// Demonstrates finding the first even number in a vector using std::find_if
#include <algorithm>
#include <iostream>
#include <vector>

bool isEven(int n)
{
    return n % 2 == 0;
}

int main()
{
    std::vector<int> numbers{ 3, 7, 10, 15, 20 };
    auto it = std::find_if(numbers.begin(), numbers.end(), isEven);
    if (it != numbers.end())
        std::cout << "First even number: " << *it << '\n';
}