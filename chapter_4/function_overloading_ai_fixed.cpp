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

// function_overloading_fixed.cpp
// Demonstrates robust function overloading with explicit type handling
#include <iostream>
#include <string>

// Overloaded function to print an integer
void print(int value)
{
    std::cout << "Integer: " << value << '\n';
}

// Overloaded function to print a double
void print(double value)
{
    std::cout << "Double: " << value << '\n';
}

// Overloaded function for int + string
void print(int value, const std::string& text)
{
    std::cout << "Integer: " << value << ", Text: " << text << '\n';
}

// Overloaded function for int + C-string (handles "Hello World" literals directly)
void print(int value, const char* text)
{
    std::cout << "Integer: " << value << ", Text: " << text << '\n';
}

// Overloaded function to print std::string
void print(const std::string& text)
{
    std::cout << "String: " << text << '\n';
}

// Overloaded function for C-style string literals (handles "Just a string" directly)  
void print(const char* text)
{
    std::cout << "C-string: " << text << '\n';
}

void print(char value)
{
    std::cout << "Character: " << value << '\n';
}

void print(bool value)
{
    std::cout << "Boolean: " << (value ? "true" : "false") << '\n';
}

int main()
{
    print(42);                 // Calls int version - exact match
    print(3.14);               // Calls double version - exact match
    print(100, "Hello World"); // Calls int + const char* version - exact match
    print("Just a string");    // Calls const char* version - exact match
    print('A');                // Calls char version - exact match
    print(true);               // Calls bool version - exact match

    return 0;
}
