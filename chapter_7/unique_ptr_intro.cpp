// unique_ptr_intro.cpp
// Demonstrates basic usage of std::unique_ptr

#include <iostream>
#include <memory>

class Resource
{
  public:
    Resource()
    {
        std::cout << "Resource acquired\n";
    }
    ~Resource()
    {
        std::cout << "Resource released\n";
    }

    void sayHello() const
    {
        std::cout << "Hello from Resource!\n";
    }
};

int main()
{
    std::unique_ptr<Resource> ptr{new Resource()}; // ptr owns the Resource

    ptr->sayHello(); // use the Resource

    // No need to call delete.
    // When main ends, ptr goes out of scope,
    // and the Resource it manages is automatically released.

    return 0;
}
