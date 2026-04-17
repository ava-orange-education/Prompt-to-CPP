// customer_app/rectangle.h
// This file defines the Rectangle class used in the customer application.
// It includes member functions for calculating area and perimeter.
#ifndef RECTANGLE_H
#define RECTANGLE_H

class Rectangle
{
  public:
    Rectangle(double w, double h);
    double area() const;
    double perimeter() const;

  private:
    double width;
    double height;
};

#endif // RECTANGLE_H
