// thread_detach.cpp 
// Demonstrates the behavior of std::thread when not detached or joined.
#include <iostream>
#include <thread>
#include <chrono>

int main()
{
    {
            std::thread my_thread([]()
                                    {
                                        while(1) 
                                        {
                                            std::cout << "Keep running...\n";
                                            std::this_thread::sleep_for(std::chrono::milliseconds(100));
                                        }
                                    });
            my_thread.detach();
    }


    while(1)
    {
        std::this_thread::sleep_for(std::chrono::seconds(2));
    }
    return 0;
}
