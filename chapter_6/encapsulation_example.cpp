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
// encapsulation_example.cpp
// This file demonstrates encapsulation in C++ using a class with both public and private members.
// It shows how to define a class with public and private members, and how to access them.
#include <iostream>

class A
{
  public:
    int var_pub;

    void print()
    {
        std::cout << "var_pub = " << var_pub << "\n";
        std::cout << "var_pri = " << var_pri << "\n";
    }

    void set_var_pri(int x)
    {
        var_pri = x;
    }

  private:
    int var_pri;
};

int main()
{
    A a;
    a.var_pub = 20;     // Direct access to public member
    a.set_var_pri(100); // Indirect access to private member
    a.print();
    return 0;
}