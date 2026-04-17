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
// sample_program_without_templates.cpp
// A simple C++ program that defines functions for different data types without using templates.

#include <cstdint>
#include <iostream>

uint8_t add_uint8(uint8_t a, uint8_t b)
{
    return a + b;
}

uint16_t add_uint16(uint16_t a, uint16_t b)
{
    return a + b;
}

float add_float(float a, float b)
{
    return a + b;
}

int main()
{
    uint8_t x1 = add_uint8(10, 20);
    uint16_t x2 = add_uint16(1000, 2000);
    float x3 = add_float(1.5f, 2.5f);

    std::cout << "uint8_t result:  " << static_cast<int>(x1) << "\n";
    std::cout << "uint16_t result: " << x2 << "\n";
    std::cout << "float result:    " << x3 << "\n";

    return 0;
}
