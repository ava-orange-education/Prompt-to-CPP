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
// sample_program_partial_specialization.cpp
// A simple C++ program that demonstrates partial specialization of a class template.
#include <iostream>

// Generic template for Pair
template <typename T1, typename T2> class Pair
{
  public:
    Pair(T1 first, T2 second) : a(first), b(second)
    {
    }

    void show() const
    {
        std::cout << "Generic Pair: " << a << ", " << b << "\n";
    }

  private:
    T1 a;
    T2 b;
};

// Partial specialization when second type is int
template <typename T1> class Pair<T1, int>
{
  public:
    Pair(T1 first, int second) : a(first), b(second)
    {
    }

    void show() const
    {
        std::cout << "Pair with int as second: " << a << ", integer = " << b << "\n";
    }

  private:
    T1 a;
    int b;
};

int main()
{
    Pair<std::string, double> p1("pi", 3.14);
    p1.show(); // uses generic version

    Pair<std::string, int> p2("count", 42);
    p2.show(); // uses partially specialized version

    return 0;
}
