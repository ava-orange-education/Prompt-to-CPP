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
// sample_map_custom_comparator_insert.cpp
#include <iostream>
#include <map>
#include <string>

// Comparator for descending order of popularity scores
bool comparePopularity(int lhs, int rhs)
{
    return lhs > rhs; // higher score appears first
}

int main()
{
    // std::map with custom comparator
    std::map<int, std::string, bool (*)(int, int)> popularProducts(comparePopularity);

    // Insert products using explicit key–value pairs
    popularProducts.insert(std::make_pair(89, "Wireless Headphones"));
    popularProducts.insert(std::make_pair(95, "Smartwatch"));
    popularProducts.insert(std::make_pair(72, "Bluetooth Speaker"));
    popularProducts.insert(std::make_pair(99, "Noise Cancelling Earbuds"));

    std::cout << "Products ranked by popularity (high to low):\n";
    for (const auto &entry : popularProducts)
    {
        std::cout << "Score: " << entry.first << ", Product: " << entry.second << '\n';
    }

    return 0;
}
