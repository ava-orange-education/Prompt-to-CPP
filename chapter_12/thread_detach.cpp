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
// thread_detach.cpp 
// Demonstrates the behavior of std::thread when not detached or joined.
#include <iostream>
#include <thread>
#include <chrono>

int main()
{
    {
            std::thread my_thread([]()
                                    {
                                        while(1) 
                                        {
                                            std::cout << "Keep running...\n";
                                            std::this_thread::sleep_for(std::chrono::milliseconds(100));
                                        }
                                    });
            my_thread.detach();
    }


    while(1)
    {
        std::this_thread::sleep_for(std::chrono::seconds(2));
    }
    return 0;
}
