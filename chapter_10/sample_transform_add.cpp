// sample_transform_add.cpp
// Demonstrates using std::transform to add elements of two vectors
#include <algorithm>
#include <iostream>
#include <vector>

int add(int a, int b) { return a + b; }

int main()
{
    std::vector<int> v1{ 1, 2, 3, 4 };
    std::vector<int> v2{ 10, 20, 30, 40 };
    std::vector<int> result(v1.size());

    // Add elements of v1 and v2, store in result
    std::transform(v1.begin(), v1.end(), v2.begin(), result.begin(), add);

    std::cout << "Element-wise sums: ";
    for (int n : result)
        std::cout << n << ' ';
}
