// ObjectSlicingExample.cpp
// Demonstrates how passing derived objects by value slices off their unique parts

#include <iostream>

class Shape
{
  public:
    virtual void draw() const
    {
        std::cout << "Drawing Shape\n";
    }
};

class Circle : public Shape
{
  public:
    void draw() const override
    {
        std::cout << "Drawing Circle\n";
    }
};

void render(Shape s)
{
    s.draw(); // Sliced: only base part exists here
}

int main()
{
    Circle c;
    render(c); // Object slicing occurs
    return 0;
}
