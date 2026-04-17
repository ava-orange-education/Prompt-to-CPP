// sample_unordered_map_dns.cpp
#include <iostream>
#include <string>
#include <unordered_map>

int main()
{
    std::unordered_map<std::string, std::string> dnsTable{ { "example.com", "93.184.216.34" },
                                                           { "google.com", "142.250.184.206" },
                                                           { "github.com", "140.82.112.4" } };

    // Insert a new domain
    dnsTable["cppreference.com"] = "151.101.0.133";

    // Update existing domain
    dnsTable["google.com"] = "142.250.190.206";

    // Display entries (unordered output)
    std::cout << "DNS Table:\n";
    for (const auto &entry : dnsTable)
    {
        std::cout << entry.first << " -> " << entry.second << '\n';
    }

    // Lookup a specific domain
    std::string query = "google.com";
    auto it = dnsTable.find(query);
    if (it != dnsTable.end())
        std::cout << "\nIP address of " << query << ": " << it->second << '\n';
    else
        std::cout << "\nDomain not found.\n";

    return 0;
}
