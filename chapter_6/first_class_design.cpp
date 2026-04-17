#include <iostream>
#include <string>
// first_class_design.cpp
// This file demonstrates a simple class design in C++.

// Class definition for Animal
class Animal
{
  private: // Properties are private to enforce encapsulation
    std::string color;
    std::string habitat;

  public:
    // Setter methods
    void setColor(const std::string &c)
    {
        color = c;
    }

    void setHabitat(const std::string &h)
    {
        habitat = h;
    }

    // Getter methods (behaviours using properties)
    void showColor() const
    {
        std::cout << "This animal's color is " << color << ".\n";
    }

    void showHabitat() const
    {
        std::cout << "This animal lives in " << habitat << ".\n";
    }
}; // Semicolon ends the class declaration
/*
struct Animal
{
  private:
    std::string color;
    std::string habitat;

  public:
    void setColor(const std::string &c)
    {
        color = c;
    }
    void setHabitat(const std::string &h)
    {
        habitat = h;
    }
    void showColor() const
    {
        std::cout << "This animal's color is " << color << ".\n";
    }
    void showHabitat() const
    {
        std::cout << "This animal lives in " << habitat << ".\n";
    }
};
*/