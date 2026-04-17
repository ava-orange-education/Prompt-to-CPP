// sample_buffer_generic.cpp
// This approach assumes a hosted environment.
// Demonstrates a hidden risk of using dynamic memory allocation in generic code
#include <iostream>
#include <vector>
#include <algorithm>

void sortSensorReadings(std::vector<double>& readings)
{
    // Hidden risk: std::vector allocates on the heap.
    // This will fail in environments without an allocator (e.g., bare-metal).
    std::sort(readings.begin(), readings.end());
}

int main()
{
    std::vector<double> data = {45.2, 12.5, 88.7, 32.1};
    sortSensorReadings(data);

    for (const auto& val : data) {
        std::cout << val << " ";
    }
    std::cout << "\n";
    
    return 0;
}