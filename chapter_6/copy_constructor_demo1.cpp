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
// copy_constructor_demo1.cpp
// This file demonstrates the use of copy constructors in C++.
// It shows how objects can be copied using the copy constructor and how it affects object lifecycle.
#include <iostream>

class MyClass
{
  private:
    int value;

  public:
    MyClass(int v) : value(v)
    {
        std::cout << "Constructor called, value = " << value << "\n";
    }

    MyClass(const MyClass &other) : value(other.value)
    {
        std::cout << "Copy constructor called, value = " << value << "\n";
    }

    void print() const
    {
        std::cout << "Value: " << value << "\n";
    }
};

int main()
{
    MyClass obj1(42);    // Regular constructor
    MyClass obj2 = obj1; // Copy constructor (copy initialization)
    MyClass obj3(obj1);  // Copy constructor (direct initialization)
    obj1.print();
    obj2.print();
    obj3.print();
    return 0;
}