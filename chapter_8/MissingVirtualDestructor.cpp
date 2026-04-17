// MissingVirtualDestructor.cpp
// Demonstrates incorrect destruction when the base destructor is not virtual

#include <iostream>
#include <memory>

class Base
{
  public:
    // Not virtual — this is the problem
    virtual ~Base()
    {
        std::cout << "Base destructor\n";
    }
};

class Derived : public Base
{
  private:
    std::unique_ptr<int[]> data;

  public:
    Derived()
    {
        data = std::make_unique<int[]>(100);
        std::cout << "Derived constructor\n";
    }

    ~Derived()
    {
        std::cout << "Derived destructor\n";
    }
};

int main()
{
    std::unique_ptr<Base> ptr = std::make_unique<Derived>();
    // Only Base destructor will be called — Derived destructor is skipped
    return 0;
}
