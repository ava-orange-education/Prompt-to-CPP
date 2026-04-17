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
// sample_program_temporary_binding.cpp
// Demonstrates binding temporaries to const lvalue and rvalue references.
// This example shows how temporaries can be safely used in function calls.
#include <iostream>
#include <string>
void processLvalue(std::string &s)
{
    std::cout << "Lvalue reference: " << s << "\n";
}
void processConstLvalue(const std::string &s)
{
    std::cout << "Const lvalue reference: " << s << "\n";
}
void processRvalue(std::string &&s)
{
    std::cout << "Rvalue reference: " << s << "\n";
}

int main()
{
    // processLvalue(std::string("Temp")); // Error: cannot bind non-const lvalue reference to temporary
    processConstLvalue(std::string("Temp")); // OK: lifetime is extended
    processRvalue(std::string("Temp"));      // OK: moves resources from temporary

    return 0;
}
