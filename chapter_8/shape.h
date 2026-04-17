#ifndef SHAPE_H
#define SHAPE_H
// shape.h
// Header file defining an abstract base class Shape and its derived classes Circle and Rectangle
class Shape
{
  public:
    virtual double area() const = 0; // Pure virtual function
    virtual ~Shape() = default;
};

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
    double width, height;
};
#endif // SHAPE_H