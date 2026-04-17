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
// unique_ptr_reset.cpp
// Demonstrates unique_ptr::reset()

#include <iostream>
#include <memory>
#include <string>

class Resource
{
  public:
    Resource(const std::string &name) : m_name{name}
    {
        std::cout << "Resource " << m_name << " acquired\n";
    }
    ~Resource()
    {
        std::cout << "Resource " << m_name << " released\n";
    }
    void sayHello() const
    {
        std::cout << "Hello from " << m_name << '\n';
    }

  private:
    std::string m_name;
};

int main()
{
    std::unique_ptr<Resource> p_res{new Resource("One")};
    p_res->sayHello();

    // Replace Resource "One" with Resource "Two"
    // Resource "One" is automatically released
    // when reset() is called
    p_res.reset(new Resource("Two"));
    p_res->sayHello();

    // Release Resource "Two" explicitly before program ends
    // Not strictly necessary here since p_res will go out of scope
    // and release the resource automatically
    p_res.reset();

    return 0;
}
