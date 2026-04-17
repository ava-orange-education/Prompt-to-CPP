// lvalue_rvalue_references.cpp
// Demonstrates the use of lvalue and rvalue references in function parameters.
#include <iostream>
#include <string>

void processLvalue(std::string &str)
{
    std::cout << "Lvalue reference: " << str << "\n";
}

void processRvalue(std::string &&str)
{
    std::cout << "Rvalue reference: " << str << "\n";
}

int main()
{
    std::string persistent = "C++11"; // lvalue: named variable
    processLvalue(persistent);        // OK: binds to lvalue
    // processRvalue(persistent);             // Error: lvalue cannot bind to rvalue reference
    processRvalue(std::string("Temp")); // OK: temporary is an rvalue
    // processLvalue(std::string("Temp"));    // Error: temporary cannot bind to lvalue reference
    processRvalue("Literal"); // OK: string literal converts to temporary
    // processLvalue("Literal");              // Error: string literal cannot bind to lvalue reference
    return 0;
}