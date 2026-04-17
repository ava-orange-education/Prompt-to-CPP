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
//  class_template_example.cpp
//  Demonstrates class templates in C++
//  This example shows how to create and use a simple class template
#include <iostream>
#include <string>

template <typename T> class MyData
{
  private:
    T m_value;

  public:
    MyData(T value) : m_value(value)
    {
    }

    void display() const
    {
        std::cout << "Value: " << m_value << '\n';
    }
};

int main()
{
    MyData<int> intData(42); // instantiate MyData with int
    intData.display();

    MyData<std::string> stringData("Hello, Templates!"); // instantiate MyData with std::string
    stringData.display();

    return 0;
}