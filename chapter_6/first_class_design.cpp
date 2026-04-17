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