// sample_program_exception_multiple.cpp
// A simple C++ program demonstrating exception handling with multiple catch blocks.
#include <iostream>
#include <stdexcept>

void validateTransaction(double amount)
{
    if (amount < 0.0)
    {
        throw std::invalid_argument("Transaction amount cannot be negative");
    }
    if (amount == 0.0)
    {
        throw std::runtime_error("Transaction amount cannot be zero");
    }
    std::cout << "Transaction of " << amount << " processed successfully.\n";
}

int main()
{
    try
    {
        validateTransaction(0.0);
    }
    catch (const std::invalid_argument &error)
    {
        std::cout << "Invalid input: " << error.what() << "\n";
    }
    catch (const std::runtime_error &error)
    {
        std::cout << "Runtime problem: " << error.what() << "\n";
    }

    return 0;
}
