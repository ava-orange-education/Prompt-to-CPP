// instantiate_class.cpp
// This file demonstrates how to instantiate a class in C++.
// It shows how to create an object of a class and use its member functions.
#include <iostream>
#include <string>

class Animal
{
  private:
    std::string colour;
    std::string habitat;

  public:
    void setColour(const std::string &c)
    {
        colour = c;
    }
    void setHabitat(const std::string &h)
    {
        habitat = h;
    }

    void showColour() const
    {
        std::cout << "This animal's colour is " << colour << ".\n";
    }
    void showHabitat() const
    {
        std::cout << "This animal lives in " << habitat << ".\n";
    }
};

int main()
{
    Animal tiger; // Instantiating the class
    tiger.setColour("orange with black stripes");
    tiger.setHabitat("forest");

    tiger.showColour();
    tiger.showHabitat();

    return 0;
}