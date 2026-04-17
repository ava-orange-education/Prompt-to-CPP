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
// ObjectSlicingExample.cpp
// Demonstrates how passing derived objects by value slices off their unique parts

#include <iostream>

class Shape
{
  public:
    virtual void draw() const
    {
        std::cout << "Drawing Shape\n";
    }
};

class Circle : public Shape
{
  public:
    void draw() const override
    {
        std::cout << "Drawing Circle\n";
    }
};

void render(Shape s)
{
    s.draw(); // Sliced: only base part exists here
}

int main()
{
    Circle c;
    render(c); // Object slicing occurs
    return 0;
}
