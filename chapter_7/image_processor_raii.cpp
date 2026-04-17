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
// image_processor_raii.cpp
// Demonstrates RAII (Resource Acquisition Is Initialization) in C++
// This example shows how to manage resources (like memory) using RAII principles
#include <iostream>
#include <stdexcept>

class ImageProcessor
{
    int *m_pixelBuffer; // resource owned by the object

  public:
    ImageProcessor()
    {
        m_pixelBuffer = new int[100]; // acquired in constructor
        std::cout << "Allocated image buffer\n";
    }

    ~ImageProcessor()
    {
        delete[] m_pixelBuffer; // always freed
        std::cout << "Freed image buffer\n";
    }

    void loadImage()
    {
        std::cout << "Loading image...\n";
        throw std::runtime_error("Image format not supported!"); // exception thrown
    }
};

int main()
{
    try
    {
        ImageProcessor img;
        img.loadImage();
    }
    catch (const std::exception &ex)
    {
        std::cout << "Caught error: " << ex.what() << '\n';
    }
    return 0;
}
