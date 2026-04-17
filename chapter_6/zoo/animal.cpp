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
