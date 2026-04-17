// sample_set_userids.cpp
#include <iostream>
#include <set>
#include <string>

int main()
{
    // Initial user IDs added in random order
    std::set<std::string> userIDs{ "charlie", "alice", "bob" };

    int count = 0;
    std::cout << "Enter number of new users: ";
    std::cin >> count;

    std::cin.ignore(); // clear leftover newline
    std::cout << "Enter " << count << " usernames:\n";

    for (int i = 0; i < count; ++i)
    {
        std::string username;
        std::getline(std::cin, username);

        // Insert automatically ignores duplicates
        auto result = userIDs.insert(username);

        if (result.second)
            std::cout << "User '" << username << "' added successfully.\n";
        else
            std::cout << "Duplicate user '" << username << "' ignored.\n";
    }

    // Display all users (automatically sorted)
    std::cout << "\nCurrent user list:\n";
    for (const auto &user : userIDs)
    {
        std::cout << "- " << user << '\n';
    }

    // Remove a specific user
    userIDs.erase("bob");

    std::cout << "\nUsers after removal:\n";
    for (const auto &user : userIDs)
    {
        std::cout << "- " << user << '\n';
    }

    // Check if a user exists
    std::string checkUser = "alice";
    if (userIDs.find(checkUser) != userIDs.end())
        std::cout << "\nUser '" << checkUser << "' exists in the system.\n";
    else
        std::cout << "\nUser '" << checkUser << "' not found.\n";

    return 0;
}
