// scoped_thread.cpp
// This code demonstrates a scoped thread wrapper in C++17.
// The scoped_thread class ensures that the thread is joined
// automatically when the scoped_thread object goes out of scope.
#include <chrono>
#include <iostream>
#include <thread>
#include <utility>

class scoped_thread
{
    std::thread t;

  public:
    explicit scoped_thread(std::thread thread) : t(std::move(thread))
    {
    }

    ~scoped_thread()
    {
        if (t.joinable())
        {
            t.join(); // Automatic cleanup on destruction
        }
    }

    scoped_thread(const scoped_thread &) = delete;
    scoped_thread &operator=(const scoped_thread &) = delete;
    scoped_thread(scoped_thread &&) = default;
    scoped_thread &operator=(scoped_thread &&) = default;
};

void worker()
{
    for (int i = 0; i < 3; ++i)
    {
        std::cout << "Worker: " << i << '\n';
        std::this_thread::sleep_for(std::chrono::milliseconds(400));
    }
}

int main()
{
    {
        scoped_thread st(std::thread(worker));
        std::cout << "Main: Doing work...\n";
        std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    } // st destructs → join() called automatically

    std::cout << "Main: Worker finished.\n";
    return 0;
}
