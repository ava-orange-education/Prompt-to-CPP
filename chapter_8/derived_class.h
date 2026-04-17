// derived_class.h
// Demonstrates inheritance in C++

#ifndef DERIVED_CLASS_H
#define DERIVED_CLASS_H
#include "base_class.h"

class SavingsAccount : public Account // Derived class
{
  public:
    // delete default constructor to enforce initialization with balance
    SavingsAccount() = delete;
    // Constructor that initialises the base Account with a starting balance
    explicit SavingsAccount(double initialBalance) : Account(initialBalance)
    {
    }

    // Additional functionality specific to SavingsAccount
    void addInterest(double ratePercent)
    {
        double interest = getBalance() * (ratePercent / 100.0);
        deposit(interest);
        std::cout << "Interest added: " << interest << '\n';
    }
};
#endif // DERIVED_CLASS_H
