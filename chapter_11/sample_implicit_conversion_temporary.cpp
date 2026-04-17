// sample_implicit_conversion_temporary.cpp
// Temporary created by implicit type conversion
// This example shows how an integer literal is implicitly converted to a double temporary

#include <iostream>

void printDouble(double value)
{
    std::cout << value << '\n';
}

int main()
{
    printDouble(5); // Integer literal 5 is implicitly converted to a temporary double

    return 0;
}
