// name_hiding.cpp
// Demonstrates name hiding in inheritance
#include <iostream>
#include <string>

class Account
{
  public:
    void withdraw(int)
    {
        std::cout << "Account::withdraw(int)\n";
    }
    void withdraw(double)
    {
        std::cout << "Account::withdraw(double)\n";
    }
};

class SavingsAccount : public Account
{
  public:
    void withdraw(const std::string &)
    {
        std::cout << "SavingsAccount::withdraw(std::string)\n";
    }
    // using Account::withdraw; // Uncomment to restore base overloads
};

int main()
{
    SavingsAccount objSavingsAccount;

    // Scenario 1: Step 1: compiler finds withdraw(std::string) in SavingsAccount → OK
    objSavingsAccount.withdraw(std::string("note"));
    // Scenario 2: Step 1: compiler sees only withdraw(std::string) in SavingsAccount
    // objSavingsAccount.withdraw(10);
    // Scenario 2: Step 2: parameter does not match → ERROR
    // objSavingsAccount.withdraw(3.5);  // Same reason → ERROR

    return 0;
}

