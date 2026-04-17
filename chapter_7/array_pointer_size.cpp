// array_pointer_pize.cpp
// Demonstrates the size of an array and a pointer to an array in C++

#include <iostream>

int main()
{
    int arr[3] = {10, 20, 30}; // An array of 3 integers
    int *p = arr;              // arr decays to pointer to first element

    std::cout << "sizeof(arr): " << sizeof(arr) << '\n'; // size of whole array (e.g., 12 bytes if int is 4 bytes)
    std::cout << "sizeof(p):   " << sizeof(p) << '\n';   // size of pointer (e.g., 8 bytes on a 64-bit system)

    return 0;
}
