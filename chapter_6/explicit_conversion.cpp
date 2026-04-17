// explicit_conversion.cpp
// This file demonstrates explicit conversion in C++.
// It shows how to use the 'explicit' keyword to prevent implicit conversions.
// In this case, an integer cannot be implicitly converted to a Distance object,
// but it can be explicitly converted using the constructor.
// This prevents accidental conversions that could lead to bugs.
// The 'explicit' keyword is used to mark constructors that should not be used for implicit conversions.
#include <iostream>

class Distance
{
  private:
    int m_metres;

  public:
    explicit Distance(int metres) : m_metres(metres)
    {
        std::cout << "Distance constructed with " << m_metres << " metres\n";
    }

    void print() const
    {
        std::cout << m_metres << " metres\n";
    }
};

void show(Distance d)
{
    d.print();
}

int main()
{
    // show(100);           // Error: implicit conversion is not allowed
    show(Distance(100)); // OK: explicit conversion
}
