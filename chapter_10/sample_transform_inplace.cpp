// sample_transform_inplace.cpp
// Demonstrates using std::transform to modify a vector in place
#include <algorithm>
#include <iostream>
#include <vector>

int doubleValue(int n) { return n * 2; }

int main()
{
    std::vector<int> numbers{ 1, 2, 3, 4, 5 };

    // Double each element in place using std::transform
    std::transform(numbers.begin(), numbers.end(), numbers.begin(), doubleValue);

    std::cout << "Doubled values: ";
    for (int n : numbers)
        std::cout << n << ' ';
}
