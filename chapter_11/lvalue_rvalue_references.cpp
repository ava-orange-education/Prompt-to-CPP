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
// lvalue_rvalue_references.cpp
// Demonstrates the use of lvalue and rvalue references in function parameters.
#include <iostream>
#include <string>

void processLvalue(std::string &str)
{
    std::cout << "Lvalue reference: " << str << "\n";
}

void processRvalue(std::string &&str)
{
    std::cout << "Rvalue reference: " << str << "\n";
}

int main()
{
    std::string persistent = "C++11"; // lvalue: named variable
    processLvalue(persistent);        // OK: binds to lvalue
    // processRvalue(persistent);             // Error: lvalue cannot bind to rvalue reference
    processRvalue(std::string("Temp")); // OK: temporary is an rvalue
    // processLvalue(std::string("Temp"));    // Error: temporary cannot bind to lvalue reference
    processRvalue("Literal"); // OK: string literal converts to temporary
    // processLvalue("Literal");              // Error: string literal cannot bind to lvalue reference
    return 0;
}