// copy_constructor_demo1.cpp
// This file demonstrates the use of copy constructors in C++.
// It shows how objects can be copied using the copy constructor and how it affects object lifecycle.
#include <iostream>

class MyClass
{
  private:
    int value;

  public:
    MyClass(int v) : value(v)
    {
        std::cout << "Constructor called, value = " << value << "\n";
    }

    MyClass(const MyClass &other) : value(other.value)
    {
        std::cout << "Copy constructor called, value = " << value << "\n";
    }

    void print() const
    {
        std::cout << "Value: " << value << "\n";
    }
};

int main()
{
    MyClass obj1(42);    // Regular constructor
    MyClass obj2 = obj1; // Copy constructor (copy initialization)
    MyClass obj3(obj1);  // Copy constructor (direct initialization)
    obj1.print();
    obj2.print();
    obj3.print();
    return 0;
}