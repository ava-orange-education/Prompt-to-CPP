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
// unique_ptr_basic_ai.cpp
// create a unique_ptr for an int and initialise it with 42
#include <iostream>
#include <memory>
int main()
{
    std::unique_ptr<int> pInt = std::make_unique<int>(42);
    std::cout << "Value: " << *pInt << std::endl;
    return 0;
}
