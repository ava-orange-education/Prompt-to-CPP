// buggy_factorial.cpp
// Bug: off-by-one error in factorial loop
// This code is intended to be used for testing static analysis tools.

#include <iostream>

unsigned long factorial(int n)
{
    unsigned long result = 1;
    for (int i = 1; i < n; ++i) // BUG: should be i <= n
    {
        result *= i;
    }
    return result;
}

int main()
{
    int num = 5;
    std::cout << "Factorial of " << num << " = " << factorial(num) << "\n";
    // Expected: 120, but prints 24
    return 0;
}