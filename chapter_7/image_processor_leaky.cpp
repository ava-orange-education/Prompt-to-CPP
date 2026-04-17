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
