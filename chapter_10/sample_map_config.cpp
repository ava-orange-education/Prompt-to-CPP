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
