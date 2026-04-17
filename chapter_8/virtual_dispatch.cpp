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
// virtual_dispatch.cpp
#include <iostream>
#include <memory>

class Account
{
  public:
    virtual ~Account() = default; // virtual destructor for safety

    virtual void withdraw(double amount) // virtual function
    {
        std::cout << "Account::withdraw: " << amount << '\n';
    }
};

class SavingsAccount : public Account
{
  public:
    void withdraw(double amount) // redefines base version
    {
        std::cout << "SavingsAccount::withdraw: " << amount << '\n';
    }
};

int main()
{
    std::unique_ptr<Account> basePtr = std::make_unique<SavingsAccount>();

    // Call goes to SavingsAccount::withdraw at runtime
    basePtr->withdraw(100.0);

    return 0;
}
