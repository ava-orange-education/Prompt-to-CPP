// exception_try_catch.cpp
// A simple C++ program demonstrating exception handling with try and catch blocks.

#include <fstream>
#include <iostream>
#include <stdexcept>

void readFile(const std::string &fileName)
{
    std::ifstream file(fileName);

    if (!file)
    {
        // If the file cannot be opened, signal this with an exception
        throw std::runtime_error("Failed to open file: " + fileName);
    }

    std::cout << "File opened successfully.\n";
    // Simulate file processing (e.g., reading content)
}

int main()
{
    try
    {
        // This file does not exist, so an exception will be thrown
        readFile("non_existent_file.txt");
    }
    catch (const std::exception &e)
    {
        std::cout << "Exception caught: " << e.what() << "\n";
    }

    std::cout << "Program continues after handling the exception safely.\n";
    return 0;
}
