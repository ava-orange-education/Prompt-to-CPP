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