/*
 * Copyright (C) 2026
 * Author: Vivek Bhadra
 * 
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program. If not, see <https://www.gnu.org/licenses/>.
 */
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
