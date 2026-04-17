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
// sample_sort_scores.cpp
// Demonstrates sorting a vector of scores in ascending and descending order
#include <algorithm>
#include <iostream>
#include <vector>

bool descending(int a, int b)
{
    return a > b;
}

int main()
{
    std::vector<int> scores{ 78, 92, 67, 84, 90 };
    // Sort ascending
    std::sort(scores.begin(), scores.end());
    std::cout << "Scores (ascending): ";
    for (int s : scores)
        std::cout << s << ' ';
    std::cout << '\n';
    // Sort descending
    std::sort(scores.begin(), scores.end(), descending);
    std::cout << "Scores (descending): ";
    for (int s : scores)
        std::cout << s << ' ';
}