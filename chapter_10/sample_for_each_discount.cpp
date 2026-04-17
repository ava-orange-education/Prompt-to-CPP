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
