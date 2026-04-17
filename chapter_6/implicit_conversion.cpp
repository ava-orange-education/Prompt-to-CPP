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
// implicit_conversion.cpp
// This file demonstrates implicit conversion in C++.
// It shows how a function can accept an object of one type and convert it implicitly from another type.
// In this case, an integer is implicitly converted to a Distance object.

#include <iostream>

class Distance
{
  private:
    int m_metres;

  public:
    Distance(int metres) : m_metres(metres)
    {
        std::cout << "Distance constructed with " << m_metres << " metres\n";
    }

    void print() const
    {
        std::cout << m_metres << " metres\n";
    }
};

void show(Distance d)
{
    d.print();
}

int main()
{
    show(100); // Implicit conversion from int to Distance
}
