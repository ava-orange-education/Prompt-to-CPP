// unique_ptr_basic_ai.cpp
// create a unique_ptr for an int and initialise it with 42
#include <iostream>
#include <memory>
int main()
{
    std::unique_ptr<int> pInt = std::make_unique<int>(42);
    std::cout << "Value: " << *pInt << std::endl;
    return 0;
}
