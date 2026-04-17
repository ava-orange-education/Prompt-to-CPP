// pointer_arithmetic_array_demo.cpp
// Demonstrates pointer arithmetic in C++ with detailed examples

#include <cstddef> // for std::ptrdiff_t
#include <iostream>

int main()
{
    int arr[4] = {10, 20, 30, 40};

    int *p = arr; // arr decays to pointer to first element
    std::cout << "Initial pointer address: " << p << ", value: " << *p << '\n';

    // Increment the pointer
    ++p;
    std::cout << "After ++p -> address: " << p << ", value: " << *p << " (moved by sizeof(int) = " << sizeof(int)
              << " bytes)\n";

    // Pointer addition
    std::cout << "At p + 1 -> address: " << (p + 1) << ", value: " << *(p + 1) << '\n';

    // Reset pointer to beginning
    p = arr;

    // Traverse array using pointer arithmetic
    std::cout << "Traversing array:\n";
    for (int i = 0; i < 4; ++i)
    {
        std::cout << "p + " << i << " -> address: " << (p + i) << ", value: " << *(p + i) << '\n';
    }

    // Pointer subtraction
    int *start = &arr[0];
    int *end = &arr[4]; // one past the last element
    std::ptrdiff_t distance = end - start;

    std::cout << "Number of elements between start and end: " << distance << '\n';

    return 0;
}