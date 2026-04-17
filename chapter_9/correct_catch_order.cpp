// correct_catch_order.cpp
// Purpose: Demonstrate correct ordering of catch blocks:
//          specific exceptions first, then general ones.

#include <iostream>
#include <stdexcept>

int main()
{
    try
    {
        // Throw a derived exception (std::out_of_range)
        throw std::out_of_range("Index out of range");
    }
    catch (const std::out_of_range &e)
    {
        std::cout << "Out of range error: " << e.what() << '\n';
    }
    catch (const std::exception &e)
    {
        std::cout << "General exception: " << e.what() << '\n';
    }

    return 0;
}
