// animal.h
// This file defines the Animal class and its derived classes Lion, Elephant, and Parrot.
// Each class has a constructor and a method to display information about the animal.
#ifndef ANIMAL_H
#define ANIMAL_H

#include <iostream>
#include <string>

class Animal
{
  protected:
    std::string m_name;

  public:
    explicit Animal(const std::string &name);
    void displayInfo() const;
    virtual ~Animal() = default;
};

class Lion : public Animal
{
  public:
    explicit Lion(const std::string &name);
    void speak() const;
};

class Elephant : public Animal
{
  public:
    explicit Elephant(const std::string &name);
    void speak() const;
};

class Parrot : public Animal
{
  public:
    explicit Parrot(const std::string &name);
    void speak() const;
};

#endif // ANIMAL_H
