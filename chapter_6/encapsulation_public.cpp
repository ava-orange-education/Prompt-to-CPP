// encapsulation_public.cpp
// This file demonstrates encapsulation in C++ using public and private access specifiers.
// It shows how to define a class with public and private members.
// The class A has a public member variable and a private member variable.
// The public member can be accessed directly, while the private member cannot be accessed from outside the class.
#include <iostream>

class A
{
  public:
    int var_pub; // Public member: can be accessed directly from outside the class

    void print()
    {
        std::cout << "var_pub = " << var_pub << "\n";
    }

  private:
    int var_pri; // Private member: cannot be accessed directly from outside the class
};

int main()
{
    A a;
    a.var_pub = 10; // Directly modifying the public member
    a.print();      // Calling the public member function

    return 0;
}
