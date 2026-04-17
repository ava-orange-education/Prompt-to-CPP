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
// sample_null_dereference.cpp
// This code demonstrates a potential null pointer dereference issue.
// It is intended to be used for testing static analysis tools.
#include <iostream>

void process(int *data)
{
    std::cout << data[0] << "\n"; // Potential null pointer dereference
}

int main()
{
    int *ptr = nullptr; // Potential null pointer
    process(ptr);       // occasionally crashes
    return 0;
}