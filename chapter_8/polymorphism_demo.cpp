// polymorphism_demo.cpp
// Sample program demonstrating runtime polymorphism using base class pointers
#include "shape.h"
#include <iostream>
#include <memory>
#include <vector>

// Function that works with a collection of Shape objects
void my_shape(const std::vector<std::unique_ptr<Shape>> &shapes)
{
    for (const auto &s : shapes)
    {
        std::cout << "Area: " << s->area() << '\n';
    }
}

int main()
{
    // Collection of base class pointers
    // Using smart pointers for automatic memory management
    std::vector<std::unique_ptr<Shape>> shapes;

    // Create and insert derived objects
    // push_back inserts a unique_ptr to a Circle object into the vector
    shapes.push_back(std::make_unique<Circle>(5.0));
    shapes.push_back(std::make_unique<Rectangle>(4.0, 6.0));

    // Process the shapes via the base class interface
    my_shape(shapes);

    return 0;
}
