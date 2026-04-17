// programme_with_use_after_free.cpp
// This code contains a use-after-free error.
// It is intended to be used for testing dynamic analysis tools like Valgrind.
#include <iostream>

int *createValue()
{
    int *p = new int(42);
    delete p; // mistake: p deleted too early
    return p; // returning a dangling pointer
}

int main()
{
    int *v = createValue();
    std::cout << *v << "\n"; // use-after-free
}
