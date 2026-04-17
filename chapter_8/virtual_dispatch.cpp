// virtual_dispatch.cpp
#include <iostream>
#include <memory>

class Account
{
  public:
    virtual ~Account() = default; // virtual destructor for safety

    virtual void withdraw(double amount) // virtual function
    {
        std::cout << "Account::withdraw: " << amount << '\n';
    }
};

class SavingsAccount : public Account
{
  public:
    void withdraw(double amount) // redefines base version
    {
        std::cout << "SavingsAccount::withdraw: " << amount << '\n';
    }
};

int main()
{
    std::unique_ptr<Account> basePtr = std::make_unique<SavingsAccount>();

    // Call goes to SavingsAccount::withdraw at runtime
    basePtr->withdraw(100.0);

    return 0;
}
