// sample_null_dereference.cpp
// This code demonstrates a potential null pointer dereference issue.
// It is intended to be used for testing static analysis tools.
#include <iostream>

void process(int *data)
{
    std::cout << data[0] << "\n"; // Potential null pointer dereference
}

int main()
{
    int *ptr = nullptr; // Potential null pointer
    process(ptr);       // occasionally crashes
    return 0;
}