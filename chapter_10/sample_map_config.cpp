
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
// sample_map_config.cpp
// Demonstrates basic usage of std::map to manage system configuration settings
#include <iostream>
#include <map>
#include <string>

int main()
{
    std::map<std::string, std::string> systemConfig{ { "hostname", "server01" },
                                                     { "ip", "192.168.1.10" },
                                                     { "os", "Linux" } };

    // Add new configuration entries
    systemConfig["version"] = "1.2.3";
    systemConfig["timezone"] = "UTC";

    // Update an existing key
    systemConfig["os"] = "Ubuntu Linux";

    // Remove a key if it exists
    systemConfig.erase("version");

    // Display current configuration
    std::cout << "System Configuration:\n";
    for (const auto &entry : systemConfig)
    {
        std::cout << "- " << entry.first << ": " << entry.second << '\n';
    }

    // Find a specific key
    auto it = systemConfig.find("hostname");
    if (it != systemConfig.end())
        std::cout << "\nHostname found: " << it->second << '\n';
    else
        std::cout << "\nHostname not found.\n";

    return 0;
}
