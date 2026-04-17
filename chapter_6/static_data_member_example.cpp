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
// static_data_member_example.cpp
// Demonstrates access to a static data member without creating an object.

#include <iostream>

class MyClass
{
  public:
    static int value;
};

// Definition of the static data member
int MyClass::value = 100;

int main()
{
    std::cout << "The static member value = " << MyClass::value << "\n";
    return 0;
}