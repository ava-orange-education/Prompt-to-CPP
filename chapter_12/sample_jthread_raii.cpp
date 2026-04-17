// sample_jthread_raii.cpp
// This code demonstrates the use of std::jthread.
// The std::jthread class automatically joins the thread
// when it goes out of scope, ensuring proper resource management.
#include <chrono>
#include <iostream>
#include <thread>

void worker()
{
    int count = 8;
    while (count--)
    {
        std::cout << "Hello there\n";
        std::this_thread::sleep_for(std::chrono::milliseconds(2));
    }
}

int main()
{
    std::jthread mythread{ worker };

    return 0;
}
