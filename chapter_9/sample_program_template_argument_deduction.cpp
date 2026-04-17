// sample_program_with_function_template.cpp
// A simple C++ program that uses a function template to add different data types.
#include <cstdint>
#include <iostream>

// Function template to add two values of the same type
// T is a placeholder for any data type
// The compiler generates the appropriate function based on the type used
// when the function is called.
template <typename T> T add(T a, T b)
{
    return a + b;
}

int main()
{
    uint8_t x1 = add<int>(10, 5.3);     // Instantiates add<uint8_t>
    uint16_t x2 = add<int>(1000, 2000); // Instantiates add<uint16_t>
    float x3 = add<float>(1.5f, 2.5f);  // Instantiates add<float>

    std::cout << "uint8_t result:  " << static_cast<int>(x1) << "\n";
    std::cout << "uint16_t result: " << x2 << "\n";
    std::cout << "float result:    " << x3 << "\n";
}
