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
// rectangle_member_functions.cpp
// This file demonstrates the use of member functions in a class.
// It shows how to define member functions outside the class definition.

#include <iostream>

class Rectangle
{
  private:
    double width;
    double height;

  public:
    Rectangle(double w, double h); // Declaration only
    double area() const;           // Declaration only
};

// Constructor defined outside the class
Rectangle::Rectangle(double w, double h) : width(w), height(h)
{
}

// Member function defined outside the class
double Rectangle::area() const
{
    return width * height;
}

int main()
{
    Rectangle rect(3.5, 2.0);
    std::cout << "Area: " << rect.area() << '\n';
    return 0;
}
