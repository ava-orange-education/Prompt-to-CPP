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
// main.cpp
// This file serves as the entry point for the zoo application.
// It creates instances of different animals and displays their information and sounds.
#include "animal.h"
#include <iostream>

int main()
{
    Lion lion("Leo");
    Elephant elephant("Ella");
    Parrot parrot("Polly");

    std::cout << "Welcome to the Zoo!" << std::endl << std::endl;

    lion.displayInfo();
    lion.speak();
    std::cout << std::endl;

    elephant.displayInfo();
    elephant.speak();
    std::cout << std::endl;

    parrot.displayInfo();
    parrot.speak();
    std::cout << std::endl;

    return 0;
}
