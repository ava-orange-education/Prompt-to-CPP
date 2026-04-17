/*
MIT License

Copyright (c) 2025 ava-orange-education

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*/

// heap_memory_example.cpp 
// This example demonstrates the difference between stack and heap memory allocation in C++.
#include <iostream>

// Stack allocation: allocated memory is automatically released when the function exits
void useStackMemory()
{
    int stackValue = 10;
    std::cout << "Stack value: " << stackValue << std::endl;
}

// Heap allocation: allocated memory remains valid even after the function returns
int *allocateHeapMemory()
{
    int *heapValue = new int(20); // Allocate on heap
    return heapValue;             // Return pointer to allocated heap memory
}

int main()
{
    useStackMemory(); // Variable created and destroyed inside the function
                      // Stack memory is automatically cleaned up when the function exits

    int *heapPtr = allocateHeapMemory();                  // Heap memory still exists
    std::cout << "Heap value: " << *heapPtr << std::endl; // Dereference pointer to access value

    delete heapPtr;    // Clean up
    heapPtr = nullptr; // Safe practice

    return 0;
}
