// function_overriding.cpp
// Sample program demonstrating function overriding in inheritance

#include <iostream>

class Account // Base class
{
  public:
    Account() = delete;                     // delete default constructor to enforce initialization with balance
    explicit Account(double initialBalance) // constructor requires a starting balance
        : m_balance{initialBalance}
    {
    }

    virtual ~Account() = default; // virtual destructor (important for polymorphic base classes)

    void deposit(double amount)
    {
        m_balance += amount;
        std::cout << "Deposited: " << amount << " | Current balance: " << m_balance << '\n';
    }

    void withdraw(double amount)
    {
        if (amount <= m_balance)
        {
            m_balance -= amount;
            std::cout << "Withdrew: " << amount << " | Current balance: " << m_balance << '\n';
        }
        else
        {
            std::cout << "Insufficient funds! Current balance: " << m_balance << '\n';
        }
    }

    double getBalance() const
    {
        return m_balance;
    }

  private:
    double m_balance; // encapsulated member data for account balance
};

class SavingsAccount : public Account // Derived class
{
  public:
    SavingsAccount() = delete;
    explicit SavingsAccount(double initialBalance) : Account{initialBalance}
    {
    }

    // Override withdraw to enforce a minimum balance requirement
    void withdraw(double amount)
    {
        std::cout << "VBDBG::" << __PRETTY_FUNCTION__ << '\n';
        const double minBalance = 100.0;
        if (getBalance() - amount >= minBalance)
        {
            Account::withdraw(amount); // call base class withdraw
        }
        else
        {
            std::cout << "Withdrawal denied! Minimum balance of " << minBalance
                      << " must be maintained. Current balance: " << getBalance() << '\n';
        }
    }

    // Additional functionality specific to SavingsAccount
    void addInterest(double ratePercent)
    {
        double interest = getBalance() * (ratePercent / 100.0);
        deposit(interest);
        std::cout << "Interest added: " << interest << '\n';
    }
};

int main()
{
    SavingsAccount savAcc(500.0);
    savAcc.deposit(200.0);
    savAcc.withdraw(100.0);  // Should succeed
    savAcc.withdraw(600.0);  // Should be denied due to min balance
    savAcc.addInterest(5.0); // Add 5% interest

    return 0;
}
