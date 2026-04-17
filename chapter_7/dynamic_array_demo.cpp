// dynamic_array_demo.cpp
// Demonstrates dynamic array allocation in C++
// This example shows how to allocate, use, and free a dynamic array
#include <iostream>

int main()
{
    // Allocate an array of 5 integers on the heap
    int *arr = new int[5];

    // Initialise the array
    for (int i = 0; i < 5; ++i)
    {
        arr[i] = (i + 1) * 10; // store 10, 20, 30, 40, 50
    }

    // Access and print the array
    std::cout << "Array elements: ";
    for (int i = 0; i < 5; ++i)
    {
        std::cout << arr[i] << " ";
    }
    std::cout << '\n';

    // Release the allocated array
    delete[] arr; // always free memory allocated with new[]

    return 0;
}
