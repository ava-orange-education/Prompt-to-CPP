// polymorphism_simple.cpp
// Demonstrates runtime polymorphism using base class pointers
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

class CurrentAccount : public Account // Another Derived class
{
  public:
    CurrentAccount() = default;

    void welcomeMessage() const override
    {
        std::cout << "Welcome to CurrentAccount!\n";
    }

    ~CurrentAccount() override = default;
};

int main()
{
    std::unique_ptr<Account> pAccount = std::make_unique<SavingsAccount>();
    pAccount->welcomeMessage(); // Calls SavingsAccount::welcomeMessage() at runtime

    // Reassign to CurrentAccount
    pAccount = std::make_unique<CurrentAccount>();
    // Calls CurrentAccount::welcomeMessage() at runtime
    pAccount->welcomeMessage();
    return 0;
}