// weak_ptr_intro.cpp
// Demonstrates basic usage of std::weak_ptr

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
    std::shared_ptr<Resource> sp1 = std::make_shared<Resource>();
    std::weak_ptr<Resource> wp = sp1; // wp observes sp1, but does not own it

    std::cout << "Shared count: " << sp1.use_count() << "\n";

    if (auto sp2 = wp.lock()) // attempt to create a shared_ptr from wp
    {
        sp2->sayHello(); // safe access
        std::cout << "Resource is still alive, shared count: " << sp2.use_count() << "\n";
    }

    sp1.reset(); // release the Resource

    if (auto sp3 = wp.lock()) // lock again after sp1 reset
    {
        sp3->sayHello(); // will not execute, Resource no longer exists
    }
    else
    {
        std::cout << "Resource already destroyed\n";
    }

    return 0;
}
