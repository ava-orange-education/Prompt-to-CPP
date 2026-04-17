// base_class.h
// Defines the base class Account
#ifndef BASE_CLASS_H
#define BASE_CLASS_H
#include <iostream>
#include <iomanip>

class Account // Base class
{
  public:
    Account() = delete;            // delete default constructor to enforce initialization with balance
    Account(double initialBalance) // constructor requires a starting balance
        : m_balance(initialBalance)
    {
    }

    void deposit(double amount)
    {
        std::cout << std::fixed << std::setprecision(2);
        m_balance += amount;
        std::cout << "Deposited: " << amount << " | Current balance: " << m_balance << '\n';
    }

    void withdraw(double amount)
    {
        std::cout << std::fixed << std::setprecision(2);
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
#endif // BASE_CLASS_H