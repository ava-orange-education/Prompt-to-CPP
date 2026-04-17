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
// sample_list_systemlog.cpp
#include <iostream>
#include <list>
#include <string>

int main()
{
    std::list<std::string> systemLog{"System boot complete", "Network initialised", "User login detected"};

    int count = 0;
    std::cout << "Enter number of new log messages: ";
    std::cin >> count;

    std::cin.ignore(); // clear newline after integer input
    std::cout << "Enter " << count << " log messages:\n";

    for (int i = 0; i < count; ++i)
    {
        std::string logEntry;
        std::getline(std::cin, logEntry);
        systemLog.push_back(logEntry); // Add log entry at the end
    }

    // Insert a maintenance message at the beginning
    systemLog.push_front("System maintenance scheduled");

    // Remove the oldest log entry (front)
    if (!systemLog.empty())
        systemLog.pop_front();

    // Display current logs
    std::cout << "\nCurrent log entries:\n";
    for (const auto &entry : systemLog)
    {
        std::cout << "- " << entry << '\n';
    }

    // Remove a specific log message if found
    for (auto it = systemLog.begin(); it != systemLog.end();)
    {
        if (*it == "Network initialised")
            it = systemLog.erase(it); // erase returns iterator to next element
        else
            ++it;
    }

    std::cout << "\nLogs after clean-up:\n";
    for (const auto &entry : systemLog)
    {
        std::cout << "- " << entry << '\n';
    }

    return 0;
}
