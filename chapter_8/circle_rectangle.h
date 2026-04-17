// circle_rectangle.h
// Derived classes Circle and Rectangle implementing Shape

#ifndef CIRCLE_RECTANGLE_H
#define CIRCLE_RECTANGLE_H

#include "shape.h"

class Circle : public Shape
{
  public:
    Circle(double r) : radius(r)
    {
    }

    double area() const override
    {
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

    double area() const override
    {
        return width * height;
    }

  private:
    double width;
    double height;
};

#endif // CIRCLE_RECTANGLE_H
