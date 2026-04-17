// base_pointer_derived_object.cpp
// Demonstrates using a base class pointer to a derived class object
#include <iostream>
#include <memory>

class Account // Base class
{
  public:
    Account() = default;

    virtual void welcomeMessage() const
    {
        std::cout << "Welcome to Account!\n";
    }

    virtual ~Account() = default;
};

class SavingsAccount : public Account // Derived class
{
  public:
    SavingsAccount() = default;

    void welcomeMessage() const override
    {
        std::cout << "Welcome to SavingsAccount!\n";
    }

    ~SavingsAccount() override = default;
};

int main()
{
    std::unique_ptr<Account> pAccount = std::make_unique<SavingsAccount>();
    pAccount->welcomeMessage(); // Calls SavingsAccount::welcomeMessage() at runtime
    return 0;
}
