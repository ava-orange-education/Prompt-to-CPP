// sample_jthread_cooperative_stop.cpp
// This code demonstrates the use of std::jthread with cooperative stopping.
// The worker function checks for stop requests and exits gracefully when a stop is requested.
#include <chrono>
#include <iostream>
#include <thread>

void worker(std::stop_token stop)
{
    int count = 100;
    while (count-- && !stop.stop_requested())
    {
        std::cout << "Hello there\n";
        std::this_thread::sleep_for(std::chrono::milliseconds(2));
    }
}

int main()
{
    std::jthread mythread{ worker };

    std::this_thread::sleep_for(std::chrono::milliseconds(100));

    return 0;
}
