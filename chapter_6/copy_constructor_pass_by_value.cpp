// copy_constructor_pass_by_value.cpp
// This file demonstrates the use of copy constructors in C++.
// It shows how objects can be copied when passed by value to a function.
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

void display(MyClass obj) // obj is passed by value, copy constructor is called
{
    std::cout << "Inside display function\n";
}

int main()
{
    MyClass obj1(10); // Regular constructor
    display(obj1);    // Copy constructor invoked when passing by value

    return 0;
}
