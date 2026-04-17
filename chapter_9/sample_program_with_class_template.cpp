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
// sample_program_with_class_template.cpp
// A simple C++ program that uses a class template to handle triples of different data types.
#include <iostream>

template <typename T> class Triple
{
  public:
    Triple(T first, T second, T third) : a(first), b(second), c(third)
    {
    }

    T maxValue() const
    {
        T maxVal = a;
        if (b > maxVal)
            maxVal = b;
        if (c > maxVal)
            maxVal = c;
        return maxVal;
    }

  private:
    T a, b, c;
};

int main()
{
    Triple<int> triInt(3, 7, 5);
    std::cout << "Max of int triple: " << triInt.maxValue() << "\n";

    Triple<double> triDouble(2.3, 6.7, 4.4);
    std::cout << "Max of double triple: " << triDouble.maxValue() << "\n";

    return 0;
}
