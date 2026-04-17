// static_data_member_example.cpp
// Demonstrates access to a static data member without creating an object.

#include <iostream>

class MyClass
{
  public:
    static int value;
};

// Definition of the static data member
int MyClass::value = 100;

int main()
{
    std::cout << "The static member value = " << MyClass::value << "\n";
    return 0;
}