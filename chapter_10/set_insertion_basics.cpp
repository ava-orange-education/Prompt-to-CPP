// set_insertion_basics.cpp
// This program demonstrates the basics of inserting elements into a set 
// and checking for duplicates.
#include <iostream>
#include <set>
#include <string>

int main() {
    std::set<std::string> userIDs;

    // The insert function returns a std::pair
    auto result = userIDs.insert("david");

    if (result.second) {
        std::cout << "User added successfully.\n";
    } else {
        std::cout << "Duplicate user ignored.\n";
    }

    return 0;
}