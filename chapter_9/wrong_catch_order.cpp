// wrong_catch_order.cpp
// Purpose: Demonstrate that placing a base-class catch
//          before a derived-class catch hides the specific handler.

#include <iostream>
#include <stdexcept>

int main()
{
    try
    {
        // Throw a derived exception (std::out_of_range)
        throw std::out_of_range("Index out of range");
    }
    catch (const std::exception &e)
    {
        // Base class handler placed first
        std::cout << "General exception: " << e.what() << '\n';
    }
    catch (const std::out_of_range &e)
    {
        // This block is never reached
        std::cout << "Out of range error: " << e.what() << '\n';
    }

    return 0;
}
