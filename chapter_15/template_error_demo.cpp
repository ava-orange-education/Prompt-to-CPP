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

