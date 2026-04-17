
// bank_account_demo.cpp
// Demonstrates usage of the Account and SavingsAccount classes
#include "derived_class.h"
#include <iostream>

int main()
{
    SavingsAccount mySavings(500.00); // start with an initial balance of 500

    mySavings.deposit(1000.00);    // add 1000 to the account
    mySavings.withdraw(200.00);    // withdraw 200
    mySavings.addInterest(5.0); // add 5% interest on the current balance

    return 0;
}
