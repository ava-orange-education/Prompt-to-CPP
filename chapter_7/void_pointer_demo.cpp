// void_pointer_demo.cpp
// Demonstrates the use of void pointers in C++
#include <iostream>

int main()
{
    int value = 42;

    void *voidPtr = &value;                    // void* can store the address of any type
    int *intPtr = static_cast<int *>(voidPtr); // cast back to int* before dereferencing

    std::cout << "Value through int*: " << *intPtr << std::endl;
    return 0;
}
