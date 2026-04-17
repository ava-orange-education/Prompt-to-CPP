// shared_ptr_intro.cpp
// Demonstrates basic usage of std::shared_ptr

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
    std::shared_ptr<Resource> p1{new Resource()}; // p1 owns the Resource
    {
        std::shared_ptr<Resource> p2 = p1; // p2 shares ownership with p1
        p2->sayHello();                    // use the Resource
        std::cout << "Resource is now shared by two pointers\n";
    } // p2 goes out of scope, but the Resource is not destroyed yet

    std::cout << "Back in main, p1 still owns the Resource\n";

    return 0; // when p1 goes out of scope, Resource is destroyed
}
