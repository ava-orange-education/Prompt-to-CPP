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
// sample_use_after_free.cpp
// This code contains a use-after-free error.
// It is intended to be used for testing static analysis tools like Cppcheck.
#include <iostream>

int main()
{
    int *value = new int(42); // allocate memory
    delete value;             // free memory

    // Intentional bug: using memory after it has been freed
    std::cout << "Value is: " << *value << "\n";

    return 0;
}
