// sample_program_temporary_binding.cpp
// Demonstrates binding temporaries to const lvalue and rvalue references.
// This example shows how temporaries can be safely used in function calls.
#include <iostream>
#include <string>
void processLvalue(std::string &s)
{
    std::cout << "Lvalue reference: " << s << "\n";
}
void processConstLvalue(const std::string &s)
{
    std::cout << "Const lvalue reference: " << s << "\n";
}
void processRvalue(std::string &&s)
{
    std::cout << "Rvalue reference: " << s << "\n";
}

int main()
{
    // processLvalue(std::string("Temp")); // Error: cannot bind non-const lvalue reference to temporary
    processConstLvalue(std::string("Temp")); // OK: lifetime is extended
    processRvalue(std::string("Temp"));      // OK: moves resources from temporary

    return 0;
}
