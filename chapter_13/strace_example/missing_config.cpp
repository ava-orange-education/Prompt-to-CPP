// missing_config.cpp
// This code attempts to read a configuration file that may not exist.
// It is intended to be used for testing static analysis tools.
#include <fstream>
#include <iostream>

int main()
{
    std::ifstream file("config.txt");
    if (!file)
    {
        std::cout << "Failed to open config file\n";
        return 1;
    }
    std::cout << "Config loaded\n";
    return 0;
}
