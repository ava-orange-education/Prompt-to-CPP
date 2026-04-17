// unique_ptr_reset.cpp
// Demonstrates unique_ptr::reset()

#include <iostream>
#include <memory>
#include <string>

class Resource
{
  public:
    Resource(const std::string &name) : m_name{name}
    {
        std::cout << "Resource " << m_name << " acquired\n";
    }
    ~Resource()
    {
        std::cout << "Resource " << m_name << " released\n";
    }
    void sayHello() const
    {
        std::cout << "Hello from " << m_name << '\n';
    }

  private:
    std::string m_name;
};

int main()
{
    std::unique_ptr<Resource> p_res{new Resource("One")};
    p_res->sayHello();

    // Replace Resource "One" with Resource "Two"
    // Resource "One" is automatically released
    // when reset() is called
    p_res.reset(new Resource("Two"));
    p_res->sayHello();

    // Release Resource "Two" explicitly before program ends
    // Not strictly necessary here since p_res will go out of scope
    // and release the resource automatically
    p_res.reset();

    return 0;
}
