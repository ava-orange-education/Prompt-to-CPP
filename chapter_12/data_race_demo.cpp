// data_race_demo.cpp
// This code demonstrates a data race condition in C++17.
// Two threads increment a shared counter variable
// without synchronization, leading to undefined behavior.
#include <iostream>
#include <thread>

int counter = 0;

void worker()
{
    for (int i = 0; i < 100000; ++i)
    {
        ++counter;
    }
}

int main()
{
    std::thread t1(worker);
    std::thread t2(worker);
    t1.join();
    t2.join();
    std::cout << "counter = " << counter << '\n';
}
