// thread_return_result.cpp
// This code demonstrates returning results from a thread in C++17.
// A worker thread processes sensor data and returns the computed
// moving average back to the main thread using std::promise and std::future.
#include <chrono>
#include <future>
#include <iostream>
#include <numeric>
#include <thread>
#include <vector>

// Function to compute moving average from sensor data
// Simulates some processing delay
double compute_moving_average(const std::vector<int> &samples)
{
    std::this_thread::sleep_for(std::chrono::milliseconds(100)); // Simulate processing
    if (samples.empty())
        return 0.0;
    // Compute average
    // std::accumulate returns long long to prevent overflow for large sums
    // so we cast to double for the final average calculation
    // Use 0LL to specify the initial value as long long
    // to avoid potential overflow with large vectors
    // and ensure correct type promotion
    return static_cast<double>(std::accumulate(samples.begin(), samples.end(), 0LL)) / samples.size();
}

int main()
{
    std::promise<std::vector<int>> data_promise;                           // Promise to send data to worker thread
    std::future<std::vector<int>> data_future = data_promise.get_future(); // Future to receive data in worker thread

    std::promise<double> result_promise;                             // Promise to send result back to main thread
    std::future<double> result_future = result_promise.get_future(); // Future to receive result in main thread

    // Worker thread: receives raw data, computes average, sends result
    std::thread worker(
        [df = std::move(data_future), &result_promise]() mutable // Capture by move to transfer ownership
        {
            try
            {
                std::vector<int> samples = df.get();          // Wait for data from main thread
                double avg = compute_moving_average(samples); // once df.get() unblocks, process the data
                result_promise.set_value(avg);                // Send result back to main thread
            }
            catch (...)
            {
                result_promise.set_exception(std::current_exception()); // Propagate exceptions
            }
        });

    // Main thread: simulates sensor input
    std::vector<int> sensor_readings = { 22, 23, 25, 24, 23, 26, 24 };
    std::cout << "Main: Sending sensor data...\n";
    data_promise.set_value(sensor_readings); // unblock the worker thread
                                             // set_value moves the data into the promise

    // Wait for result
    std::cout << "Main: Waiting for processed average...\n";
    double average = result_future.get();                      // blocks until the worker thread sets the value
    std::cout << "Main: Moving average = " << average << "\n"; // main thread now unblocked and has the result

    worker.join(); // Ensure worker thread has finished
    return 0;
}
