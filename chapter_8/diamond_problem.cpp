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
// diamond_problem.cpp
// Demonstrates the diamond problem in C++

#include <iostream>
#include <string>

class StaffMember
{
  public:
    void showDepartment() const
    {
        std::cout << "Department: Operations\n";
    }
};

class Trainer : public StaffMember
{
};

class Evaluator : public StaffMember
{
};

class TrainingCoordinator : public Trainer, public Evaluator
{
};

int main()
{
    TrainingCoordinator coordinator;

    // coordinator.showDepartment(); // Error: ambiguous
    coordinator.Trainer::showDepartment();
    coordinator.Evaluator::showDepartment();

    return 0;
}