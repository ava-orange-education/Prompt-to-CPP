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

// Write multiple overloaded versions of a function named 'print' in C++.
// Each version should take a different type or number of arguments.
// For example: one with int, one with double, one with two parameters (int, string), etc.
#include <iostream>
#include <string>
using namespace std;

// Overloaded function to print an integer
void print(int value)
{
    cout << "Integer: " << value << endl;
}

void print(double value)
{
    cout << "Double: " << value << endl;
}
void print(int value, const string &text)
{
    cout << "Integer: " << value << ", Text: " << text << endl;
}
void print(const string &text)
{
    cout << "Text: " << text << endl;
}
void print(char value)
{
    cout << "Character: " << value << endl;
}
void print(bool value)
{
    cout << "Boolean: " << (value ? "true" : "false") << endl;
}
int main()
{
    print(42);                 // Calls the int version
    print(3.14);               // Calls the double version
    print(100, "Hello World"); // Calls the int and string version
    print("Just a string");    // Calls the string version
    print('A');                // Calls the char version
    print(true);               // Calls the bool version

    return 0;
}
