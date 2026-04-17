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
// volatile_demo.cpp
#include <chrono>
#include <iostream>
#include <thread>
volatile bool running = true; // Assume another thread sets running = false
int main()
{
    std::cout << "System running: " << running << "\n";
    while (running)
    {
        std::this_thread::sleep_for(std::chrono::seconds(1)); // Wait 1 second
    }
    std::cout << "System stopped: " << running << std::endl;
    return 0;
}
