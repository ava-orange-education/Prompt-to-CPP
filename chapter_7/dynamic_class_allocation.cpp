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
// dynamic_class_allocation.cpp
// Demonstrates allocation and deallocation of a class object

#include <iostream>

class Box
{
  public:
    Box(int length, int width, int height) : m_length{length}, m_width{width}, m_height{height}
    {
        std::cout << "Box constructed: " << m_length << "x" << m_width << "x" << m_height << '\n';
    }

    ~Box()
    {
        std::cout << "Box destroyed\n";
    }

    int volume() const
    {
        return m_length * m_width * m_height;
    }

  private:
    int m_length;
    int m_width;
    int m_height;
};

int main()
{
    // Allocate a Box object dynamically
    Box *pBox = new Box(3, 4, 5); // dynamically allocated Box object,
                                  // parameters are length, width, height to the constructor
                                  // pBox points to the allocated Box object
    // Use the Box object
    // pBox is a pointer to the Box object
        std::cout << "Box volume: " << pBox->volume() << '\n';

    // Deallocate the object
    delete pBox;

    return 0;
}
