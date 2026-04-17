// set_emplace_usage.cpp
// This program demonstrates the use of emplace to construct elements directly in a set.
#include <iostream>
#include <set>
#include <string>

int main() {
    std::set<std::string> userIDs;

    // Constructing the string directly inside the set's node
    userIDs.emplace("frank");

    return 0;
}