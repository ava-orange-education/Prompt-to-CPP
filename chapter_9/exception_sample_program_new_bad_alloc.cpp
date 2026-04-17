// sample_program_new_bad_alloc.cpp
#include <iostream>
#include <new>

int main()
{
    try
    {
        // Try to allocate a huge block (likely to fail)
        double *data = new double[1000000000000ULL];
        delete[] data;
    }
    catch (const std::bad_alloc &e)
    {
        std::cout << "Memory allocation failed: " << e.what() << "\n";
    }

    return 0;
}
