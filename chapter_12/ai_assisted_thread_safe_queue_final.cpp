// /home/vbhadra/OrangeAVA/projects/chapter_12/ai_assisted_thread_safe_queue.cpp
#include <chrono>
#include <condition_variable>
#include <iostream>
#include <mutex>
#include <optional>
#include <queue>
#include <thread>

template <typename T> class ThreadSafeQueue
{
  public:
    ThreadSafeQueue() = default;
    ThreadSafeQueue(const ThreadSafeQueue &) = delete;
    ThreadSafeQueue &operator=(const ThreadSafeQueue &) = delete;

    // Signal that no more items will be pushed. Wake any waiting threads.
    void close()
    {
        {
            std::lock_guard<std::mutex> lock(m_mutex);
            m_closed = true;
        }
        m_cv.notify_all();
    }

    // Push a value into the queue (copy)
    void push(const T &value)
    {
        {
            std::lock_guard<std::mutex> lock(m_mutex);
            m_queue.push(value);
        }
        m_cv.notify_one();
    }

    // Push a value into the queue (move)
    void push(T &&value)
    {
        {
            std::lock_guard<std::mutex> lock(m_mutex);
            m_queue.push(std::move(value));
        }
        m_cv.notify_one();
    }

    // Try to pop. Returns std::optional<T> (empty if queue was empty)
    std::optional<T> try_pop()
    {
        std::lock_guard<std::mutex> lock(m_mutex);
        if (m_queue.empty())
            return std::nullopt;
        T value = std::move(m_queue.front());
        m_queue.pop();
        return value;
    }

    // Blocking pop with clean shutdown.
    // Waits until an item is available or the queue is closed.
    std::optional<T> wait_and_pop()
    {
        std::unique_lock<std::mutex> lock(m_mutex);

        // Wait until either there is data or the queue is closed
        m_cv.wait(lock, [this]() { return !m_queue.empty() || m_closed; });

        // If queue is closed and empty, return immediately
        if (m_queue.empty() && m_closed)
            return std::nullopt;

        T value = std::move(m_queue.front());
        m_queue.pop();
        return value;
    }

    bool empty() const noexcept
    {
        std::lock_guard<std::mutex> lock(m_mutex);
        return m_queue.empty();
    }

    size_t size() const noexcept
    {
        std::lock_guard<std::mutex> lock(m_mutex);
        return m_queue.size();
    }

    bool is_closed() const noexcept
    {
        std::lock_guard<std::mutex> lock(m_mutex);
        return m_closed;
    }

  private:
    mutable std::mutex m_mutex;
    std::condition_variable m_cv;
    std::queue<T> m_queue;
    bool m_closed{ false };
};

// Small demonstration: producer-consumer
int main()
{
    ThreadSafeQueue<int> q;

    std::thread producer(
        [&q]()
        {
            for (int i = 0; i < 10; ++i)
            {
                q.push(i);
                std::cout << "Produced: " << i << '\n';
                std::this_thread::sleep_for(std::chrono::milliseconds(100));
            }

            // No more items to produce — close the queue
            q.close();
            std::cout << "Producer finished and closed the queue.\n";
        });

    std::thread consumer(
        [&q]()
        {
            while (true)
            {
                auto item = q.wait_and_pop();

                // End of queue reached after closure
                if (!item.has_value())
                {
                    std::cout << "Consumer detected closed queue. Exiting.\n";
                    break;
                }

                std::cout << "Consumed: " << *item << '\n';
            }
        });

    producer.join();
    consumer.join();

    return 0;
}