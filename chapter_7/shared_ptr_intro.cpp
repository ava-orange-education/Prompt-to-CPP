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
// shared_ptr_intro.cpp
// Demonstrates basic usage of std::shared_ptr

#include <iostream>
#include <memory>

class Resource
{
  public:
    Resource()
    {
        std::cout << "Resource acquired\n";
    }
    ~Resource()
    {
        std::cout << "Resource released\n";
    }

    void sayHello() const
    {
        std::cout << "Hello from Resource!\n";
    }
};

int main()
{
    std::shared_ptr<Resource> p1{new Resource()}; // p1 owns the Resource
    {
        std::shared_ptr<Resource> p2 = p1; // p2 shares ownership with p1
        p2->sayHello();                    // use the Resource
        std::cout << "Resource is now shared by two pointers\n";
    } // p2 goes out of scope, but the Resource is not destroyed yet

    std::cout << "Back in main, p1 still owns the Resource\n";

    return 0; // when p1 goes out of scope, Resource is destroyed
}
