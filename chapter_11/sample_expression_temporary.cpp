// sample_expression_temporary.cpp
// Demonstrates temporaries created during expression evaluation.
// This example shows how temporary objects are created in expressions.

#include <iostream>
#include <string>

int main()
{
    std::string fullName = std::string("John") + " " + "Doe";
    std::cout << fullName << '\n'; // Temporaries hold intermediate concatenation results

    return 0;
}
