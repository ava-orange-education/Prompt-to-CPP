// sample_program_exception_forwarding.cpp
// Demonstrate logging locally and then rethrowing.

#include <iostream>
#include <stdexcept>

void processData()
{
    try
    {
        throw std::runtime_error("Data corruption detected");
    }
    catch (const std::runtime_error &e)
    {
        std::cout << "Logging error: " << e.what() << '\n';
        throw; // rethrow to the caller
    }
}

int main()
{
    try
    {
        processData();
    }
    catch (const std::exception &e)
    {
        std::cout << "Main handler caught: " << e.what() << '\n';
    }

    return 0;
}
