/*
 * Copyright (C) 2026
 * Author: Vivek Bhadra
 * 
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program. If not, see <https://www.gnu.org/licenses/>.
 */
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