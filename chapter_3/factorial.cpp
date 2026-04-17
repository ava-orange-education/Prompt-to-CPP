// factorial.cpp
// Demonstrates recursion in C++ to compute factorial.
#include <iostream>

// Function to calculate factorial recursively
unsigned long long factorial(unsigned long long n)
{
    if (n <= 1)
        return 1;                // Base case: factorial of 0 or 1 is 1
    return n * factorial(n - 1); // Recursive case: n! = n * (n-1)!
}

int main()
{
    int n;
    std::cout << "Enter a non-negative integer to compute its factorial: ";
    std::cin >> n;

    // Basic input validation
    if (n < 0)
    {
        std::cout << "Error: Factorial is not defined for negative numbers." << "\n";
        return 1;
    }

    unsigned long long result = factorial(static_cast<unsigned long long>(n));
    std::cout << "Factorial of " << n << " is " << result << "\n";

    return 0;
}