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
// sample_for_each_discount.cpp
// Demonstrates using std::for_each to apply a discount to each product in a vector
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

struct Product
{
    std::string name;
    double price;
};

void applyDiscount(Product &product)
{
    constexpr double discountRate = 0.10; // 10% discount
    product.price *= (1.0 - discountRate);
    std::cout << "Discounted price for " << product.name << ": $" << product.price << '\n';
}

int main()
{
    std::vector<Product> inventory{
        { "Laptop", 1200.0 }, { "Smartphone", 800.0 }, { "Headphones", 150.0 }, { "Monitor", 300.0 }
    };

    // Apply discount and log for each product
    std::for_each(inventory.begin(), inventory.end(), applyDiscount);
}
