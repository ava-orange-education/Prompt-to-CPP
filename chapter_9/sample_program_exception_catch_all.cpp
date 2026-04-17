// sample_program_exception_catch_all.cpp
// A simple C++ program demonstrating exception handling with multiple
// catch blocks including a catch-all.
#include <iostream>
#include <stdexcept>

void performOperation(int value)
{
    if (value < 0)
    {
        throw std::invalid_argument("Negative values are not allowed");
    }
    if (value == 0)
    {
        throw std::runtime_error("Value must not be zero");
    }
    if (value > 100)
    {
        throw "Value exceeds maximum limit"; // raw string thrown
    }

    std::cout << "Operation completed on value: " << value << "\n";
}

int main()
{
    try
    {
        performOperation(200);
    }
    catch (const std::invalid_argument &error)
    {
        std::cout << "Invalid argument: " << error.what() << "\n";
    }
    catch (const std::runtime_error &error)
    {
        std::cout << "Runtime error: " << error.what() << "\n";
    }
    catch (...)
    {
        std::cout << "An unknown exception occurred.\n";
    }
}
