// copy_assignment_operator.cpp
// This file demonstrates the use of copy assignment operator in C++.
// It shows how objects can be assigned values from other objects using the copy assignment operator.
#include <iostream>

class MyClass
{
  public:
    MyClass(int v) : value(v)
    {
        std::cout << "Constructor called, value = " << value << '\n';
    }

    // Copy assignment operator
    MyClass &operator=(const MyClass &other)
    {
        if (this != &other)
        { // Prevent self-assignment
            value = other.value;
            std::cout << "Copy assignment operator called, value = " << value << '\n';
        }
        return *this;
    }
    private:
       int value;
};

int main()
{
    MyClass obj1(10);
    MyClass obj2(20);

    obj2 = obj1; // Calls copy assignment operator

    return 0;
}
