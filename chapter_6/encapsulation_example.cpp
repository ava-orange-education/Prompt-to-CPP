// encapsulation_example.cpp
// This file demonstrates encapsulation in C++ using a class with both public and private members.
// It shows how to define a class with public and private members, and how to access them.
#include <iostream>

class A
{
  public:
    int var_pub;

    void print()
    {
        std::cout << "var_pub = " << var_pub << "\n";
        std::cout << "var_pri = " << var_pri << "\n";
    }

    void set_var_pri(int x)
    {
        var_pri = x;
    }

  private:
    int var_pri;
};

int main()
{
    A a;
    a.var_pub = 20;     // Direct access to public member
    a.set_var_pri(100); // Indirect access to private member
    a.print();
    return 0;
}