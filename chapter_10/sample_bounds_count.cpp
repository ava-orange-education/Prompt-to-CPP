// sample_bounds_count.cpp
// Demonstrates using std::lower_bound and std::upper_bound to count occurrences of
// a key in a sorted vector
#include <algorithm>
#include <iostream>
#include <vector>

int main()
{
    std::vector<int> v{ 10, 20, 20, 20, 30, 40 }; // sorted vector
    int key = 20;

    auto lb = std::lower_bound(v.begin(), v.end(), key); // first element >= key
    auto ub = std::upper_bound(v.begin(), v.end(), key); // first element > key

    std::cout << "Count: " << (ub - lb) << '\n'; // prints 3
}
