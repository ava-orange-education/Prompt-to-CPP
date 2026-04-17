// virtual_inheritance_demo.cpp
// Demonstrates how virtual inheritance resolves the diamond problem in C++

#include <iostream>

class StaffMember
{
  public:
    void showDepartment() const
    {
        std::cout << "Department: Operations\n";
    }
};

class Trainer : virtual public StaffMember
{
};

class Evaluator : virtual public StaffMember
{
};

class TrainingCoordinator : public Trainer, public Evaluator
{
};

int main()
{
    TrainingCoordinator coordinator;
    coordinator.showDepartment(); // No ambiguity now

    return 0;
}