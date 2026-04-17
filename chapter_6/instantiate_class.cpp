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