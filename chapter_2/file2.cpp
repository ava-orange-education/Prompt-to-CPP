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
// file2.cpp
#include <iostream>

// Declaration only; tells the compiler this exists elsewhere
extern int sharedCount;

void showSharedCount(); // Declaration of function defined in file1.cpp

int main()
{
    std::cout << "Accessing sharedCount from file2.cpp: " << sharedCount << "\n";
    showSharedCount(); // Call function from file1.cpp
    return 0;
}