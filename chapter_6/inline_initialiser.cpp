// inline_initialiser.cpp
// This file demonstrates the use of in-class member initialisers and constructor member initialiser lists in C++.
// The Animal class has three member variables: m_colour, m_habitat, and m_id.
// The default constructor uses in-class member initialisers, while the parameterised constructor uses a member initialiser list to override the defaults.
// The main function creates two Animal objects and prints their information to the console.
#include <iostream>
#include <string>

class Animal
{
  public:
    // Default constructor: uses in-class member initialisers.
    Animal()
    {
    }

    // Parameterised constructor: member initialiser list overrides in-class defaults.
    Animal(int id, const std::string &colour, const std::string &habitat)
        : m_colour{colour}, m_habitat{habitat}, m_id{id}
    {
    }

    void printInfo() const
    {
        std::cout << "Animal{id=" << m_id
                  << ", colour=" << m_colour
                  << ", habitat=" << m_habitat << "}\n";
    }

  private:
    std::string m_colour{"unknown"};
    std::string m_habitat{"unknown"};
    const int m_id{0}; // in-class initialisation, overridden by constructor list
};

int main()
{
    Animal a;
    a.printInfo();

    Animal b(7, "white", "jungle");
    b.printInfo();

    return 0;
}