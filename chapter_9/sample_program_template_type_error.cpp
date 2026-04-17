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
// sample_program_template_type_error.cpp
// A simple C++ program that demonstrates a template type error when using unsupported types.
#include <iostream>
#include <string>

template <typename T> T add(T a, T b)
{
    return a + b; // '+' must be valid for T
}

int main()
{
    std::string s1 = "Hello, ";
    std::string s2 = "World!";
    std::cout << add<std::string>(s1, s2) << "\n"; // OK: string supports '+'

    // Uncommenting the following lines will cause a compile error,
    // because '+' is not defined for const char*.
    const char* c1 = "Hello, ";
    const char* c2 = "World!";
    std::cout << add<const char*>(c1, c2) << "\n";

    return 0;
}
