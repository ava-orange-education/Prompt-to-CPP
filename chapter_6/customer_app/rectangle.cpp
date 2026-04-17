//  rectangle_member_functions.cpp
// This file demonstrates the use of member functions in a class.
// It shows how to define member functions outside the class definition.
#include "rectangle.h"

Rectangle::Rectangle(double w, double h) : width(w), height(h)
{
}

double Rectangle::area() const
{
    return width * height;
}

double Rectangle::perimeter() const
{
    return 2.0 * (width + height);
}
