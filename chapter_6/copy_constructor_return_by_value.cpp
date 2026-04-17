// copy_constructor_return_by_value.cpp
// This file demonstrates the use of copy constructors in C++.
// It shows how objects can be copied when returned by value from a function.
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
};

MyClass createObject()
{
    MyClass temp(20); // Regular constructor
    return temp;      // May invoke copy constructor (or elided/moved)
}

int main()
{
    MyClass obj2 = createObject(); // Copy constructor may be invoked here
    return 0;
}
