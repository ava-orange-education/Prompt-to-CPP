// animal.cpp
// This file implements the Animal class and its derived classes.
// It includes member functions to display information about different animals.
#include "animal.h"

Animal::Animal(const std::string &name) : m_name(name)
{
}

void Animal::displayInfo() const
{
    std::cout << "Animal: " << m_name << std::endl;
}

Lion::Lion(const std::string &name) : Animal(name)
{
}

void Lion::speak() const
{
    std::cout << m_name << " says: Roar!" << std::endl;
}

Elephant::Elephant(const std::string &name) : Animal(name)
{
}

void Elephant::speak() const
{
    std::cout << m_name << " says: Trumpet!" << std::endl;
}

Parrot::Parrot(const std::string &name) : Animal(name)
{
}

void Parrot::speak() const
{
    std::cout << m_name << " says: Squawk!" << std::endl;
}
