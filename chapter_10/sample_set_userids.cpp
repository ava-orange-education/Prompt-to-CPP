/*
 * Copyright (C) 2026
 * Author: Vivek Bhadra
 * 
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program. If not, see <https://www.gnu.org/licenses/>.
 */
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
