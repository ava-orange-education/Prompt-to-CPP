// sample_find_names.cpp
// Demonstrates finding a name in a vector using std::find
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

int main()
{
    std::vector<std::string> names{ "Alice", "Bob", "Charlie", "David" };

    auto it = std::find(names.begin(), names.end(), "Charlie");
    if (it != names.end())
        std::cout << "Found: " << *it << '\n';
    else
        std::cout << "Name not found.\n";

    return 0;
}
