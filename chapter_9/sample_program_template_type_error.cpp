// sample_program_template_type_error.cpp
// A simple C++ program that demonstrates a template type error when using unsupported types.
#include <iostream>
#include <string>

template <typename T> T add(T a, T b)
{
    return a + b; // '+' must be valid for T
}

int main()
{
    std::string s1 = "Hello, ";
    std::string s2 = "World!";
    std::cout << add<std::string>(s1, s2) << "\n"; // OK: string supports '+'

    // Uncommenting the following lines will cause a compile error,
    // because '+' is not defined for const char*.
    // const char* c1 = "Hello, ";
    // const char* c2 = "World!";
    // std::cout << add<const char*>(c1, c2) << "\n";

    return 0;
}
