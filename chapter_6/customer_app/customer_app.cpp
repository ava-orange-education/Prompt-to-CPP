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
// customer_app/customer_app.cpp
// This file is the main entry point for the customer application.
// It includes the Rectangle class and demonstrates its usage.
#include "rectangle.h"
#include <iostream>

int main()
{
    Rectangle r(5.0, 3.0);
    std::cout << "Area: " << r.area() << '\n';
    std::cout << "Perimeter: " << r.perimeter() << '\n';
    return 0;
}
