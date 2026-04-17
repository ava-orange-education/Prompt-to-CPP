//  class_template_example.cpp
//  Demonstrates class templates in C++
//  This example shows how to create and use a simple class template
#include <iostream>
#include <string>

template <typename T> class MyData
{
  private:
    T m_value;

  public:
    MyData(T value) : m_value(value)
    {
    }

    void display() const
    {
        std::cout << "Value: " << m_value << '\n';
    }
};

int main()
{
    MyData<int> intData(42); // instantiate MyData with int
    intData.display();

    MyData<std::string> stringData("Hello, Templates!"); // instantiate MyData with std::string
    stringData.display();

    return 0;
}