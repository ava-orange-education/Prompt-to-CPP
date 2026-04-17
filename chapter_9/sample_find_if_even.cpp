// sample_find_if_even.cpp
#include <algorithm>
#include <iostream>
#include <vector>

bool isEven(int n) { return n % 2 == 0; }

int main() {
    std::vector<int> numbers{3, 7, 10, 15, 20};
    auto it = std::find_if(numbers.begin(), numbers.end(), isEven);
    if (it != numbers.end())
        std::cout << "First even number: " << *it << '\n';

    return 0;
}