// sample_vector_sensors.cpp
#include <iostream>
#include <vector>

int main()
{
    std::vector<double> sensorReadings{ 23.5, 24.1, 22.8, 23.9, 25.0 };
    int count = 0;

    std::cout << "Enter number of additional sensor readings to record: ";
    std::cin >> count;

    std::cout << "Enter " << count << " temperature readings (in °C):\n";

    for (int i = 0; i < count; ++i)
    {
        double reading = 0.0;
        if (std::cin >> reading)
        {
            sensorReadings.push_back(reading);
        }
        else
        {
            std::cerr << "Invalid input detected. Exiting.\n";
            return 1;
        }
    }

    // Remove the oldest reading if available
    if (!sensorReadings.empty())
        sensorReadings.erase(sensorReadings.begin());

    // Compute average temperature
    double sum = 0.0;
    for (const double reading : sensorReadings)
    {
        sum += reading;
    }
    double avg = sensorReadings.empty() ? 0.0 : sum / sensorReadings.size();

    // Find the highest reading
    double maxReading = 0.0;
    if (!sensorReadings.empty())
    {
        maxReading = sensorReadings[0];
        for (const double reading : sensorReadings)
        {
            if (reading > maxReading)
                maxReading = reading;
        }
    }

    std::cout << "Average temperature: " << avg << " °C\n";
    std::cout << "Highest reading: " << maxReading << " °C\n";

    return 0;
}