// name_hiding_scope_resolution_operator.cpp
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
    objSavingsAccount.withdraw(std::string("note"));


    // The following lines use the scope resolution operator (::) to explicitly call the base class (Account) versions of withdraw.
    objSavingsAccount.Account::withdraw(10);
    objSavingsAccount.Account::withdraw(3.5);

    return 0;
}

