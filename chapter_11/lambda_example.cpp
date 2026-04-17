// File: lambda_example.cpp
// Purpose: Demonstrate a simple lambda that checks if a sensor reading exceeds a threshold.

#include <iostream>

int main()
{
    double threshold = 25.0;

    // Define a lambda that checks if a sensor reading exceeds the threshold
    auto isHighTemp = [threshold](double value) -> bool { return value > threshold; };

    // Simulated sensor readings
    double readings[] = { 22.5, 25.1, 24.9, 26.3 };

    for (double reading : readings)
    {
        if (isHighTemp(reading))
            std::cout << "Reading " << reading << "°C exceeds the threshold of " << threshold << "°C\n";
        else
            std::cout << "Reading " << reading << "°C is within safe limits.\n";
    }

    return 0;
}
