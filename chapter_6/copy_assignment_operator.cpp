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
// copy_assignment_operator.cpp
// This file demonstrates the use of copy assignment operator in C++.
// It shows how objects can be assigned values from other objects using the copy assignment operator.
#include <iostream>

class MyClass
{
  public:
    MyClass(int v) : value(v)
    {
        std::cout << "Constructor called, value = " << value << '\n';
    }

    // Copy assignment operator
    MyClass &operator=(const MyClass &other)
    {
        if (this != &other)
        { // Prevent self-assignment
            value = other.value;
            std::cout << "Copy assignment operator called, value = " << value << '\n';
        }
        return *this;
    }
    private:
       int value;
};

int main()
{
    MyClass obj1(10);
    MyClass obj2(20);

    obj2 = obj1; // Calls copy assignment operator

    return 0;
}
