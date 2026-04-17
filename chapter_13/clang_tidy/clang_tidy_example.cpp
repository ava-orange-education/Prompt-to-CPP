// clang_tidy_example.cpp
// This program contains a subtle issue detectable by clang-tidy.
// It is intended for static analysis using clang-tidy.

#include <iostream>

int add(int a, int b)
{
    return a + b;
}

int main()
{
    double value = 42.7;

    int truncated = value; // implicit narrowing conversion

    int sum = add(truncated, 10);
    std::cout << "Sum: " << sum << "\n";

    return 0;
}
