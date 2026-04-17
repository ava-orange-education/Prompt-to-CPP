/*
 * Copyright (C) 2026
 * Author: Vivek Bhadra
 * 
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program. If not, see <https://www.gnu.org/licenses/>.
 */
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