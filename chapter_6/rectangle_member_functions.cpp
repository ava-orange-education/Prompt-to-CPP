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
