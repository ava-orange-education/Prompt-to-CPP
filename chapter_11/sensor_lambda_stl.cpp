// sensor_lambda_stl.cpp
// Demonstrates the use of lambdas with STL algorithms to process sensor readings.
// This example includes sorting, filtering, counting, and averaging sensor data.
#include <algorithm>
#include <numeric>
#include <iostream>
#include <vector>

void printReadings(const std::vector<double> &readings, const std::string &label)
{
    std::cout << label << ": ";
    for (double value : readings)
    {
        std::cout << value << " ";
    }
    std::cout << '\n';
}

int main()
{
    std::vector<double> readings = { 23.5, 26.2, 24.8, 27.1, 22.9 };

    // Sort readings in descending order using a lambda
    std::sort(readings.begin(), readings.end(), [](double a, double b) -> bool { return a > b; });

    std::cout << "Sorted readings (descending): ";
    printReadings(readings, "Sorted readings");

    // Filter readings above 25°C using a lambda
    double threshold = 25.0;
    std::vector<double> highReadings;
    std::copy_if(readings.begin(), readings.end(), std::back_inserter(highReadings),
                 [threshold](double value) { return value > threshold; });

    std::cout << "High readings (> 25°C): ";
    printReadings(highReadings, "High readings");

    // Count high readings using a lambda with a reference capture
    int alertCount = 0;
    std::for_each(readings.begin(), readings.end(),
                  [&alertCount](double value)
                  {
                      if (value > 25.0)
                          ++alertCount;
                  });

    std::cout << "Number of high readings: " << alertCount << '\n';

    // Compute average temperature using a lambda with std::accumulate
    auto sum = std::accumulate(readings.begin(), 
                    readings.end(),
                    0.0,
                    [](double acc, double val)
                    {
                        return acc + val;
                    });
    std::cout << "Sum of readings: " << sum << '\n';
    double average = sum / readings.size();
    std::cout << "Average temperature: " << average << '\n';

    return 0;
}