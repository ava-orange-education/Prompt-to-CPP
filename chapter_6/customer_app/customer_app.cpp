// customer_app/customer_app.cpp
// This file is the main entry point for the customer application.
// It includes the Rectangle class and demonstrates its usage.
#include "rectangle.h"
#include <iostream>

int main()
{
    Rectangle r(5.0, 3.0);
    std::cout << "Area: " << r.area() << '\n';
    std::cout << "Perimeter: " << r.perimeter() << '\n';
    return 0;
}
