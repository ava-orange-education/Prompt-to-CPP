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
