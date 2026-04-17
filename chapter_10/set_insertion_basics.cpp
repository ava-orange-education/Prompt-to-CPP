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