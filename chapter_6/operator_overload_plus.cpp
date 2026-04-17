// operator_overload_plus.cpp
// This file demonstrates operator overloading in C++.
// It shows how to overload the + operator for a custom class Alpha.
// The class Alpha has a member variable and a member function to overload the + operator.
// The overloaded operator returns a new Alpha object with the sum of the member variables.
// The main function creates two Alpha objects, adds them using the overloaded + operator, and prints the result.

#include <iostream>

class Alpha
{
  private:
    int m_value;

  public:
    Alpha(int value) : m_value(value)
    {
    }

    // Member function to overload the + operator
    Alpha operator+(const Alpha &other) const
    {
        return Alpha(m_value + other.m_value);
    }

    void print() const
    {
        std::cout << m_value << '\n';
    }
};

int main()
{
    Alpha a(10);
    Alpha b(20);
    Alpha result = a + b;

    result.print(); // Output: 30

    return 0;
}
