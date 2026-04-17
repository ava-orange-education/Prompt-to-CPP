// unique_lock_flexible.cpp
// This code demonstrates the flexible locking capabilities of std::unique_lock in C++17.
// A worker thread conditionally acquires a lock based on a shared flag
// to update a shared counter variable.
#include <chrono>
#include <iostream>
#include <mutex>
#include <thread>

std::mutex mtx;
int shared_counter = 0;
bool enable_update = false;

void worker_thread()
{
    std::unique_lock<std::mutex> lock(mtx, std::defer_lock); // Lock deferred

    // Simulate some preparation work before acquiring the lock
    std::this_thread::sleep_for(std::chrono::milliseconds(200));
    if (!enable_update)
    {
        std::cout << "Worker: Update disabled, skipping critical section.\n";
        return;
    }

    lock.lock(); // Lock only when condition is true
    std::cout << "Worker: Lock acquired, updating shared counter...\n";
    shared_counter += 10;
    std::this_thread::sleep_for(std::chrono::milliseconds(300));
    lock.unlock(); // Manual unlock

    std::cout << "Worker: Lock released after update.\n";
}

int main()
{
    std::cout << "Main: Preparing system...\n";
    std::thread t(worker_thread);

    std::this_thread::sleep_for(std::chrono::milliseconds(100));
    {
        std::lock_guard<std::mutex> guard(mtx);
        enable_update = true;
        std::cout << "Main: Update enabled.\n";
    }

    t.join();
    std::cout << "Main: Final shared counter = " << shared_counter << '\n';
    return 0;
}
