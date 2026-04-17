// sample_program_template_instantiation.cpp
// A simple C++ program that demonstrates explicit template instantiation.
#include <iostream>

template <typename T> T add(T a, T b)
{
    return a + b; // requires '+' to be valid for T
}

int main()
{
    int x = add<int>(3, 4);           // Instantiates add<int>
    double y = add<double>(2.5, 4.1); // Instantiates add<double>

    std::cout << "int result:    " << x << "\n";
    std::cout << "double result: " << y << "\n";

    return 0;
}
