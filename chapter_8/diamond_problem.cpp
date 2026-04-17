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