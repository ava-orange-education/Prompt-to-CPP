// set_traversal_example.cpp
// This program demonstrates how to traverse a set of user IDs and print them in sorted order.
#include <iostream>
#include <set>
#include <string>

int main()
{
    std::set<std::string> userIDs
    {
        "alice",
        "charlie",
        "bob"
    };

    for (auto& user : userIDs)
    {
        std::cout << user << '\n';
    }

    return 0;
}