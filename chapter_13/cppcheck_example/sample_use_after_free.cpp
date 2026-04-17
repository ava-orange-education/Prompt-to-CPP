// sample_use_after_free.cpp
// This code contains a use-after-free error.
// It is intended to be used for testing static analysis tools like Cppcheck.
#include <iostream>

int main()
{
    int *value = new int(42); // allocate memory
    delete value;             // free memory

    // Intentional bug: using memory after it has been freed
    std::cout << "Value is: " << *value << "\n";

    return 0;
}
