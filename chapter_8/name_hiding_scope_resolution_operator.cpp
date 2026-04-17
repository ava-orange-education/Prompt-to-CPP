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

