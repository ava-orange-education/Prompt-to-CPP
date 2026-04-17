// mutex_lock_guard_demo.cpp
// Demonstrates basic mutual exclusion using std::mutex and std::lock_guard.
// Two threads increment a shared counter safely without race conditions.

#include <iostream>
#include <mutex>
#include <thread>

std::mutex mtx;
int counter = 0;

void worker()
{
    for (int i = 0; i < 100000; ++i)
    {
        std::lock_guard<std::mutex> lock(mtx); // Lock acquired automatically
        ++counter;                             // Safe increment
    }
    // Lock is released automatically when lock goes out of scope
}

int main()
{
    std::thread t1(worker);
    std::thread t2(worker);

    t1.join();
    t2.join();

    std::cout << "Final counter value: " << counter << '\n';
    return 0;
}
