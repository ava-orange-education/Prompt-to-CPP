// inheritance.cpp
// This file demonstrates inheritance in C++.
// It shows how a derived class can inherit from a base class and extend its functionality.
// The Dog class inherits from the Animal class and adds a new method specific to dogs.
#include <iostream>

class Animal
{
  public:
    void speak() const
    {
        std::cout << "Animal makes a sound\n";
    }
};

class Dog : public Animal
{
  public:
    void bark() const
    {
        std::cout << "Dog barks\n";
    }
};

int main()
{
    Dog d;
    d.speak(); // inherited from Animal
    d.bark();  // defined in Dog
}
