// dynamic_memory_demo.cpp
// Demonstrates dynamic memory allocation in C++
#include <iostream>

int main()
{
    // Allocate a single int on the heap, initialised to 42
    int *p = new int(42);

    std::cout << "Value at allocated memory: " << *p << '\n';
    std::cout << "Address of allocated memory: " << p << '\n';

    // Release the allocated memory
    delete p;
    p = nullptr; // good practice to avoid dangling pointer

    return 0;
}