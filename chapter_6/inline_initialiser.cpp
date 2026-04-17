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