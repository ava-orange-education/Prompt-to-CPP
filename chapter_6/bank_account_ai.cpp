// Create a C++ class for a BankAccount with deposit, withdraw, and balance-check methods
#include <iostream>
#include <stdexcept>

class BankAccount
{
  private:
    double balance;

  public:
    // Constructor to initialize the account with a starting balance
    BankAccount(double initial_balance) : balance(initial_balance)
    {
        if (initial_balance < 0)
        {
            throw std::invalid_argument("Initial balance cannot be negative.");
        }
    }

    // Method to deposit money into the account
    void deposit(double amount)
    {
        if (amount <= 0)
        {
            throw std::invalid_argument("Deposit amount must be positive.");
        }
        balance += amount;
    }

    // Method to withdraw money from the account
    void withdraw(double amount)
    {
        if (amount <= 0)
        {
            throw std::invalid_argument("Withdrawal amount must be positive.");
        }
        if (amount > balance)
        {
            throw std::out_of_range("Insufficient funds for withdrawal.");
        }
        balance -= amount;
    }

    // Method to check the current balance
    double getBalance() const
    {
        return balance;
    }
};

// Example usage
int main()
{
    try
    {
        BankAccount account(100.0); // Create an account with an initial balance of 100.0
        account.deposit(50.0);      // Deposit 50.0
        std::cout << "Current Balance: " << account.getBalance() << std::endl; // Should print 150.0

        account.withdraw(30.0);                                                // Withdraw 30.0
        std::cout << "Current Balance: " << account.getBalance() << std::endl; // Should print 120.0

        account.withdraw(200.0); // Attempt to withdraw more than the balance (should throw an exception)
    }
    catch (const std::exception &e)
    {
        std::cerr << "Error: " << e.what() << std::endl; // Catch and print any exceptions
    }

    return 0;
}