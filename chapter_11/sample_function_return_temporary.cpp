// sample_function_return_temporary.cpp
// Function returning an object by value creating a temporary
// This example shows how a temporary object can be used to initialize a variable.

#include <iostream>
#include <string>

std::string makeGreeting()
{
    return "Hello, World!"; // Temporary std::string constructed here
}

int main()
{
    std::string message = makeGreeting(); // Temporary initializes 'message'
    std::cout << message << '\n';

    return 0;
}
