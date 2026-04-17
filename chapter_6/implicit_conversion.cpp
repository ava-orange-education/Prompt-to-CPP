// implicit_conversion.cpp
// This file demonstrates implicit conversion in C++.
// It shows how a function can accept an object of one type and convert it implicitly from another type.
// In this case, an integer is implicitly converted to a Distance object.

#include <iostream>

class Distance
{
  private:
    int m_metres;

  public:
    Distance(int metres) : m_metres(metres)
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
    show(100); // Implicit conversion from int to Distance
}
