#include <iostream>
#include <vector>
#include <algorithm>

struct Task {
    int id;
    Task(int i) : id(i) {}
};

int main() {
    std::vector<Task> workflow;
    workflow.push_back(Task(10));
    workflow.push_back(Task(5));

    // Error: std::sort requires the < operator, which Task lacks.
    std::sort(workflow.begin(), workflow.end());

    return 0;
}

