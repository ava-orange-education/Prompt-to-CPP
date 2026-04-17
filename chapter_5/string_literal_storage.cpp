/**
 * @file    string_literal_storage.cpp
 * @author  Vivek Bhadra
 *
 * @brief
 * Demonstrates the use of string literals in C++ and highlights that
 * identical string literals may reside in read-only memory.
 *
 * @license
 * This file is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation; either version 3 of the License, or (at your
 * option) any later version.
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 */

// string_literal_storage.cpp
// Demonstrates that identical string literals may share the same memory address.
#include <iostream>

void printGreeting()
{
    const char* msg = "Hello, learner!";
    std::cout << "Inside function: " << msg
              << " | address: " << static_cast<const void*>(msg) << '\n';
}

int main()
{
    const char* msg = "Hello, learner!";
    std::cout << "In main: " << msg
              << " | address: " << static_cast<const void*>(msg) << '\n';

    printGreeting();
    return 0;
}