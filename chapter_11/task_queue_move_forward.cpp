// task_queue_move_forward.cpp
// Demonstrates a TaskQueue class that uses lvalue and rvalue references
// along with perfect forwarding to efficiently manage tasks.
// This example shows how to add tasks using copies and moves.
#include <iostream>
#include <string>
#include <utility>
#include <vector>

class TaskQueue
{
    std::vector<std::string> tasks;

  public:
    // Add lvalue (copy)
    void enqueue(std::string &task)
    {
        tasks.push_back(task);
        std::cout << "Enqueued lvalue task: " << task << "\n";
    }

    // Add rvalue (move)
    void enqueue(std::string &&task)
    {
        tasks.push_back(std::move(task));
        std::cout << "Enqueued rvalue task: " << task << "\n";
    }

    // Template with perfect forwarding
    template <typename T> void enqueue(T &&task)
    {
        tasks.push_back(std::forward<T>(task));
        std::cout << "Enqueued forwarded task: " << task << "\n";
    }

    void printTasks() const
    {
        for (const auto &task : tasks)
        {
            std::cout << "Task: " << task << "\n";
        }
    }
};

int main()
{
    TaskQueue queue;
    std::string persistentTask = "Process data";

    // Lvalue overload: copy
    queue.enqueue(persistentTask);

    // Rvalue overload: move
    queue.enqueue(std::string("Temporary task"));

    // Use std::move to move an lvalue
    std::string movableTask = "Analyze logs";
    queue.enqueue(std::move(movableTask));
    std::cout << "After move, movableTask is: " << movableTask << "\n"; // Empty or unspecified

    // Perfect forwarding: handles both lvalues and rvalues
    queue.enqueue(persistentTask); // Copies
    queue.enqueue("Ad-hoc task");  // Moves

    queue.printTasks();
    return 0;
}