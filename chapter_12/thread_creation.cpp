// thread_creation.cpp
// This code demonstrates the creation and management of a thread in C++17.
// A separate thread is spawned to simulate sampling data from a sensor
// while the main thread continues to perform other tasks.
#include <chrono>
#include <iostream>
#include <thread>

void sample_sensor()
{
    for (int i = 0; i < 5; ++i)
    {
        std::cout << "Sample " << i << ": 23.4 C\n";
        std::this_thread::sleep_for(std::chrono::milliseconds(800));
    }
}

int main()
{
    std::thread sensor_thread(sample_sensor);

    std::cout << "Main: Processing control loop...\n";
    std::this_thread::sleep_for(std::chrono::milliseconds(2000));

    sensor_thread.join();
    return 0;
}