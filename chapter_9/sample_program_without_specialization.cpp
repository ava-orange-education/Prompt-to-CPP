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
// sample_program_without_specialization.cpp
// A simple C++ program that demonstrates a class template without specialization.
// This program defines a class template MyData that can hold a value of any type
// and provides a method to get the size of the data.
#include <iostream>
#include <string>

template<typename T>
class MyData
{
public:
    explicit MyData(const T& val) : data{val} {}

    std::size_t getMyDataSize() const
    {
        return sizeof(data);
    }

private:
    T data;
};

int main()
{
    MyData<int> d1(10);
    std::cout << "Size of int: " << d1.getMyDataSize() << "\n";

    MyData<double> d2(8.05);
    std::cout << "Size of double: " << d2.getMyDataSize() << "\n";

    MyData<float> d3(20.06f);
    std::cout << "Size of float: " << d3.getMyDataSize() << "\n";

    MyData<char> d4('A');
    std::cout << "Size of char: " << d4.getMyDataSize() << "\n";

    std::string mystr = "Hello World";
    MyData<std::string> d5(mystr);
    std::cout << "Size of string: " << d5.getMyDataSize() << "\n";

    return 0;
}