// set_find_example.cpp
// This program demonstrates how to search for a user ID in a std::set using find().

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

    const std::string targetUser{"alice"};

    auto it = userIDs.find(targetUser);

    if (it != userIDs.end())
    {
        std::cout << "User found: " << *it << '\n';
    }
    else
    {
        std::cout << "User not found: " << targetUser << '\n';
    }

    return 0;
}