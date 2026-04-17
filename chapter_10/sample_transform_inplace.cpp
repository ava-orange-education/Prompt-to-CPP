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
// sample_transform_inplace.cpp
// Demonstrates using std::transform to modify a vector in place
#include <algorithm>
#include <iostream>
#include <vector>

int doubleValue(int n) { return n * 2; }

int main()
{
    std::vector<int> numbers{ 1, 2, 3, 4, 5 };

    // Double each element in place using std::transform
    std::transform(numbers.begin(), numbers.end(), numbers.begin(), doubleValue);

    std::cout << "Doubled values: ";
    for (int n : numbers)
        std::cout << n << ' ';
}
