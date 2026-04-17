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
// static_vs_nonstatic.cpp
// This file demonstrates the difference between static and non-static members in C++.
// It shows how static members are shared across all instances of a class, while non-static members are unique to each
// instance.
#include <iostream>

class Counter
{
  private:
    int value{0};              // non-static: each object has its own 'value'
    static int instance_count; // static: one shared count for the whole class

  public:
    Counter()
    {
        ++instance_count;
    }
    explicit Counter(int v) : value(v)
    {
        ++instance_count;
    }

    void set(int v)
    {
        value = v;
    } // non-static member function (needs an object)
    int get() const
    {
        return value;
    }

    static int instances()
    { // static member function (no object required)
        return instance_count;
    }
};

// single definition of the static data member (required in C++11)
int Counter::instance_count = 0;

int main()
{
    std::cout << "Instances at start: " << Counter::instances() << '\n';

    Counter a(5); // a.value == 5
    Counter b(7); // b.value == 7

    std::cout << "Instances after creating a and b: " << Counter::instances() << '\n';
    std::cout << "a = " << a.get() << ", b = " << b.get() << '\n';

    // Accessing the static member function through an object is allowed,
    // but using the class name is clearer.
    std::cout << "Instances via object : " << a.instances() << '\n';
    std::cout << "Instances via class  : " << Counter::instances() << '\n';

    return 0;
}
