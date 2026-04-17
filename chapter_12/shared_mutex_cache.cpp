// shared_mutex_cache.cpp
// This code demonstrates the use of std::shared_mutex in C++17.
// Multiple reader threads can access the cache concurrently,
// while a single writer thread has exclusive access to update the cache.
#include <chrono>
#include <iostream>
#include <map>
#include <mutex>
#include <shared_mutex>
#include <string>
#include <thread>
#include <vector>

std::shared_mutex smtx;
std::map<std::string, int> cache = { { "alpha", 1 }, { "beta", 2 }, { "gamma", 3 } };

void reader(int id)
{
    std::shared_lock<std::shared_mutex> lock(smtx); // Multiple readers allowed
    std::cout << "Reader " << id << " reading cache...\n";
    for (const auto &[key, value] : cache)
    {
        std::cout << "Reader " << id << ": " << key << " = " << value << '\n';
        std::this_thread::sleep_for(std::chrono::milliseconds(50));
    }
    std::cout << "Reader " << id << " finished reading.\n";
}

void writer()
{
    std::unique_lock<std::shared_mutex> lock(smtx); // Exclusive write
    std::cout << "Writer updating cache...\n";
    cache["delta"] = 4;
    cache["alpha"] = 10; // Modify an existing entry
    std::this_thread::sleep_for(std::chrono::milliseconds(150));
    std::cout << "Writer finished updating.\n";
}

int main()
{
    std::cout << "Main: Starting readers and writer.\n";

    std::thread r1(reader, 1);
    std::thread r2(reader, 2);
    std::thread w(writer);
    std::thread r3(reader, 3);

    r1.join();
    r2.join();
    w.join();
    r3.join();

    std::cout << "Main: Final cache contents:\n";
    for (const auto &[key, value] : cache)
    {
        std::cout << key << " = " << value << '\n';
    }

    return 0;
}
