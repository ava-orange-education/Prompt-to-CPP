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
// operator_overload_plus.cpp
// This file demonstrates operator overloading in C++.
// It shows how to overload the + operator for a custom class Alpha.
// The class Alpha has a member variable and a member function to overload the + operator.
// The overloaded operator returns a new Alpha object with the sum of the member variables.
// The main function creates two Alpha objects, adds them using the overloaded + operator, and prints the result.

#include <iostream>

class Alpha
{
  private:
    int m_value;

  public:
    explicit Alpha(int value) : m_value(value)
    {
    }

    // Member function to overload the + operator
    Alpha operator+(const Alpha &other) const
    {
        return Alpha(m_value + other.m_value);
    }

    void print() const
    {
        std::cout << m_value << '\n';
    }
};

int main()
{
    Alpha a(10);
    Alpha b(20);
    Alpha result = a + b;

    result.print(); // Output: 30

    return 0;
}
