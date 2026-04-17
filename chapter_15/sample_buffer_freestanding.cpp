// sample_buffer_freestanding.cpp
//  A freestanding-compliant implementation.
// This version respects environment constraints by avoiding 
// heap-based containers and utilizing an in-place insertion sort.

#include <cstddef>

void sortSensorReadings(double* buffer, std::size_t count)
{
    if (buffer == nullptr || count < 2)
    {
        return;
    }

    // Insertion sort: In-place, O(1) auxiliary space, no heap allocation.
    for (std::size_t i = 1; i < count; ++i)
    {
        const double key = buffer[i];
        std::size_t j = i;

        while (j > 0 && buffer[j - 1] > key)
        {
            buffer[j] = buffer[j - 1];
            --j;
        }

        buffer[j] = key;
    }
}

int main()
{
    // Allocation occurs on the stack, satisfying the zero-heap requirement.
    double sensorReadings[8] = {23.4, 19.8, 25.1, 18.6, 22.0, 21.9, 24.3, 20.5};

    sortSensorReadings(sensorReadings, 8);

    return 0;
}