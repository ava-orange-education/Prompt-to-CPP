// thread_detach_example.cpp
// Demonstrates detaching a background thread for system monitoring
#include <chrono>
#include <iostream>
#include <thread>

void monitor_system()
{
    auto start = std::chrono::steady_clock::now();
    while ((std::chrono::steady_clock::now() - start) < std::chrono::seconds(8))
    {
        std::cout << "[Monitor] Checking system health...\n";
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }
    std::cout << "[Monitor] Timed out and shutting down cleanly.\n";
}

int main()
{
    std::cout << "Main: Starting server...\n";
    
    {
        // Launch and detach background monitoring thread
        std::thread monitor_thread(monitor_system);
        monitor_thread.detach();
    }

    // Simulate main server activity (shorter than monitor timeout)
    for (int i = 0; i < 5; ++i)
    {
        std::cout << "Main: Handling client request " << i << '\n';
        std::this_thread::sleep_for(std::chrono::milliseconds(800));
    }

    std::cout << "Main: Server shutting down.\n";
    return 0;
}