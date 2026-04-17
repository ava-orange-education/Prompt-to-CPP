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
// image_processor_leaky.cpp
// Demonstrates how an exception can skip delete[] and cause a memory leak

#include <iostream>
#include <stdexcept>

class ImageProcessor
{
  public:
    void load_image()
    {
        int *pixel_buffer = new int[100]; // simulate an image buffer
        std::cout << "Loading image...\n";

        // Simulate a failure
        throw std::runtime_error("Image format not supported!");

        // Never reached if exception occurs -> memory leak
        delete[] pixel_buffer;
    }
};

int main()
{
    try
    {
        ImageProcessor img;
        img.load_image();
    }
    catch (const std::exception &ex)
    {
        std::cout << "Caught error: " << ex.what() << '\n';
    }
    return 0;
}
