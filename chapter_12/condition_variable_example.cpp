// condition_variable_example.cpp
// This code demonstrates the use of std::condition_variable in C++17.
// A producer thread generates data and notifies a consumer thread,
// which waits until data becomes available before processing it.

#include <condition_variable>
#include <iostream>
#include <mutex>
#include <thread>
#include <vector>

std::mutex mtx;             	// Mutex for synchronizing access
std::condition_variable cv; 	// Condition variable for notification
bool ready = false;         	// data availability flag
std::vector<int> shared_data;	// Shared data

void producer()
{
    {
        std::lock_guard<std::mutex> lock(mtx); 	// Lock the mutex
        shared_data.push_back(42); 		        // data populated by producer
        ready = true;
        std::cout << "Producer: data produced.\n";
    }                // Unlocks mutex here
    cv.notify_one(); // Notify one waiting thread
                     // or cv.notify_all() to wake all waiting threads
}

void consumer()
{
    std::unique_lock<std::mutex> lock(mtx); // we need more control over the lock
                                            // hence std::unique_lock, not std::lock_guard
    cv.wait(lock, [] { return ready; });    // Wait until ready becomes true
    int value = shared_data.back();
    shared_data.pop_back(); // Consume data
    std::cout << "Consumer: received -> " << value << '\n';
}

int main()
{
    std::thread t1(consumer); // Start consumer thread first
    std::thread t2(producer); // Then start producer thread

    t1.join(); // Wait for consumer to finish
    t2.join(); // Wait for producer to finish

    return 0;
}
