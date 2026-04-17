// sample_sort_scores.cpp
// Demonstrates sorting a vector of scores in ascending and descending order
#include <algorithm>
#include <iostream>
#include <vector>

bool descending(int a, int b)
{
    return a > b;
}

int main()
{
    std::vector<int> scores{ 78, 92, 67, 84, 90 };
    // Sort ascending
    std::sort(scores.begin(), scores.end());
    std::cout << "Scores (ascending): ";
    for (int s : scores)
        std::cout << s << ' ';
    std::cout << '\n';
    // Sort descending
    std::sort(scores.begin(), scores.end(), descending);
    std::cout << "Scores (descending): ";
    for (int s : scores)
        std::cout << s << ' ';
}