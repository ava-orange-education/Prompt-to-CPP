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
// function that takes a shared_ptr<string> by const reference and prints it
#include <algorithm>
#include <cctype>
#include <iostream>
#include <iterator>
#include <list>
#include <locale>
#include <map>
#include <memory>
#include <set>
#include <string>
#include <unordered_map>
#include <vector>

void printString(const std::shared_ptr<std::string> &pStr)
{
    if (pStr)
    {
        std::cout << *pStr << '\n';
    }
    else
    {
        std::cout << "Null string pointer\n";
    }
}