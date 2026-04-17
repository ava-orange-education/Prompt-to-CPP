// name_hiding.cpp
// Demonstrates name hiding in inheritance
#include <iostream>
#include <string>

class Account
{
  public:
    void withdraw(int value)
    {
        std::cout << "Account::withdraw(int): " << value << '\n';
    }
    void withdraw(double value)
    {
        std::cout << "Account::withdraw(double): " << value << '\n';
    }
};

class SavingsAccount : public Account
{
  public:
    void withdraw(const std::string &str)
    {
        std::cout << "SavingsAccount::withdraw(std::string): " << str << '\n';
    }
    // using Account::withdraw; // Uncomment to restore base overloads
};

int main()
{
    SavingsAccount objSavingsAccount;

    // Scenario 1: Step 1: compiler finds withdraw(std::string) in SavingsAccount → OK
    objSavingsAccount.withdraw("note");

    // The following lines use the scope resolution operator (::) to explicitly call
    // the base class (Account) versions of withdraw, even though the object is of the derived type.
    // This is useful if the derived class hides or overrides some base class methods.

    // Calls Account::withdraw(int) with argument 10
    objSavingsAccount.Account::withdraw(10);

    // Calls Account::withdraw(double) with argument 3.5
    objSavingsAccount.Account::withdraw(3.5);
}