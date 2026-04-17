// vector_traversal.cpp
// Demonstrates different methods of traversing and modifying a vector in C++.
#include <iostream>
#include <vector>

int main()
{
    std::vector<int> values = {1, 2, 3, 4, 5, 6};

    for(int val : values)
        val = val + 1;  // Modifies only the copy, not the original vector
    
    for(int val : values)
        std::cout << val << " ";
    std::cout << "\n";

    for(int& val : values)
        val = val + 1;  // Modifies the original vector
    for(int& val : values)
        std::cout << val << " ";
    std::cout << "\n";

    for(const int& val : values)
    {
        // val = val + 1;  // Error: cannot modify a const reference
        std::cout << val << " ";
    }
    std::cout << "\n";

    return 0;
}
