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
// static_counter_demo.cpp
#include <iostream>

// Function with a static local variable
void counter()
{
    static int count = 0; // This retains its value between calls
    count++;
    std::cout << "Counter: " << count << "\n";
}

int main()
{
    counter(); // Output: Counter: 1
    counter(); // Output: Counter: 2
    counter(); // Output: Counter: 3
    return 0;
}
