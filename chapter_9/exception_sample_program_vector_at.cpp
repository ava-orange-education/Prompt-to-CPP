// sample_program_vector_at_exception.cpp
#include <iostream>
#include <stdexcept>
#include <vector>

int main()
{
    std::vector<int> numbers = {1, 2, 3};

    try
    {
        int value = numbers.at(5); // out of range
        std::cout << "Value: " << value << "\n";
    }
    catch (const std::out_of_range &e)
    {
        std::cout << "Caught exception: " << e.what() << "\n";
    }
}
