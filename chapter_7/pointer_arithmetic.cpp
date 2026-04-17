// pointer_arithmetic.cpp
// Demonstrates pointer arithmetic in C++

#include <iostream>

int main()
{
    int arr[3] = {10, 20, 30};
    int *p = arr; // arr decays to pointer to first element

    std::cout << *p << '\n';       // 10
    std::cout << *(p + 1) << '\n'; // 20
    std::cout << *(p + 2) << '\n'; // 30

    return 0;
}
