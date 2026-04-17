// calibrated_reduction_main.cpp
// This code demonstrates a custom reduction operation using a functor to process
// high-frequency telemetry data in C++17.
#include <numeric>
#include <vector>
#include <iostream>

struct CalibratedAccumulator
{
    double factor;

    explicit CalibratedAccumulator(double f)
        : factor(f)
    {
    }

    double operator()(double acc, double raw) const
    {
        constexpr double kelvinToCelsius = 273.15;
        return acc + (raw * factor - kelvinToCelsius);
    }
};

int main()
{
    // High-frequency telemetry data (example values)
    const std::vector<double> rawReadings{ 546.3, 548.1, 547.2, 549.0 };

    if (rawReadings.empty())
    {
        std::cerr << "Error: No telemetry data available.\n";
        return 1;
    }

    CalibratedAccumulator calibrator{ 0.5 };

    const double total = std::accumulate(rawReadings.begin(),
                                         rawReadings.end(),
                                         0.0,
                                         calibrator);

    const double average = total / static_cast<double>(rawReadings.size());

    std::cout << "Processed " << rawReadings.size() << " readings.\n";
    std::cout << "Mean calibrated temperature: " << average << " °C\n";

    return 0;
}
