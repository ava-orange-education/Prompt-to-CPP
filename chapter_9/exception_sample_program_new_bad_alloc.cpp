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
// sample_program_new_bad_alloc.cpp
#include <iostream>
#include <new>

int main()
{
    try
    {
        // Try to allocate a huge block (likely to fail)
        double *data = new double[1000000000000ULL];
        delete[] data;
    }
    catch (const std::bad_alloc &e)
    {
        std::cout << "Memory allocation failed: " << e.what() << "\n";
    }

    return 0;
}
