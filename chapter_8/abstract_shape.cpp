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
// abstract_shape.cpp
// Sample program demonstrating abstract classes and pure virtual functions
#include <iostream>

class Shape
{
  public:
    virtual double area() const = 0; // Pure virtual function
    virtual ~Shape() = default;      // Virtual destructor
};

class Circle : public Shape
{
  public:
    Circle(double r) : radius(r)
    {
    }

    // Override area to provide concrete implementation
    double area() const override
    { // Concrete implementation
        return 3.14159 * radius * radius;
    }

  private:
    double radius;
};

class Rectangle : public Shape
{
  public:
    Rectangle(double w, double h) : width(w), height(h)
    {
    }

    // Override area to provide concrete implementation
    double area() const override
    { // Different implementation
        return width * height;
    }

  private:
    double width, height;
};

int main()
{
    // Shape s; // Error: cannot instantiate abstract class

    Circle c(5.0);
    Rectangle r(4.0, 6.0);

    std::cout << "Circle area: " << c.area() << '\n';
    std::cout << "Rectangle area: " << r.area() << '\n';

    return 0;
}