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
// MissingVirtualDestructor.cpp
// Demonstrates incorrect destruction when the base destructor is not virtual

#include <iostream>
#include <memory>

class Base
{
  public:
    // Not virtual — this is the problem
    virtual ~Base()
    {
        std::cout << "Base destructor\n";
    }
};

class Derived : public Base
{
  private:
    std::unique_ptr<int[]> data;

  public:
    Derived()
    {
        data = std::make_unique<int[]>(100);
        std::cout << "Derived constructor\n";
    }

    ~Derived()
    {
        std::cout << "Derived destructor\n";
    }
};

int main()
{
    std::unique_ptr<Base> ptr = std::make_unique<Derived>();
    // Only Base destructor will be called — Derived destructor is skipped
    return 0;
}
