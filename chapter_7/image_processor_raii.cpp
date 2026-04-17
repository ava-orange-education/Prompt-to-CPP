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
