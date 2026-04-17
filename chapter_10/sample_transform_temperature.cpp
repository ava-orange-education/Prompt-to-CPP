// sample_transform_temperature.cpp
// Demonstrates using std::transform to convert Celsius to Fahrenheit
#include <algorithm>
#include <iostream>
#include <vector>

double toFahrenheit(double c)
{
    return (c * 9.0 / 5.0) + 32.0;
}

int main()
{
    std::vector<double> celsius{ 0.0, 10.0, 20.0, 30.0 };
    std::vector<double> fahrenheit(celsius.size());

    // Apply 'toFahrenheit' to each element in 'celsius', store results in 'fahrenheit'
    std::transform(celsius.begin(), celsius.end(), fahrenheit.begin(), toFahrenheit);

    std::cout << "Temperatures in Fahrenheit: ";
    for (double f : fahrenheit)
        std::cout << f << ' ';
}
