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
// encapsulation_public.cpp
// This file demonstrates encapsulation in C++ using public and private access specifiers.
// It shows how to define a class with public and private members.
// The class A has a public member variable and a private member variable.
// The public member can be accessed directly, while the private member cannot be accessed from outside the class.
#include <iostream>

class A
{
  public:
    int var_pub; // Public member: can be accessed directly from outside the class

    void print()
    {
        std::cout << "var_pub = " << var_pub << "\n";
    }

  private:
    int var_pri; // Private member: cannot be accessed directly from outside the class
};

int main()
{
    A a;
    a.var_pub = 10; // Directly modifying the public member
    a.print();      // Calling the public member function

    return 0;
}
