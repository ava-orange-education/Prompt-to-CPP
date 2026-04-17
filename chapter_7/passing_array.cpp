// passing_array.cpp
// Demonstrates passing an array to a function in C++
#include <iostream>

void print_array(int arr[], int size)
{
    for (int i = 0; i < size; ++i)
        std::cout << arr[i] << " ";
    std::cout << '\n';
}

int main()
{
    int data[4] = {1, 2, 3, 4};
    print_array(data, 4); // array decays to pointer
    return 0;
}
