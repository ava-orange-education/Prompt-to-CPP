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
// missing_config.cpp
// This code attempts to read a configuration file that may not exist.
// It is intended to be used for testing static analysis tools.
#include <fstream>
#include <iostream>

int main()
{
    std::ifstream file("config.txt");
    if (!file)
    {
        std::cout << "Failed to open config file\n";
        return 1;
    }
    std::cout << "Config loaded\n";
    return 0;
}
