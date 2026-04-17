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

