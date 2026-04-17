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
// base_pointer_derived_object.cpp
// Demonstrates using a base class pointer to a derived class object
#include <iostream>
#include <memory>

class Account // Base class
{
  public:
    Account() = default;

    virtual void welcomeMessage() const
    {
        std::cout << "Welcome to Account!\n";
    }

    virtual ~Account() = default;
};

class SavingsAccount : public Account // Derived class
{
  public:
    SavingsAccount() = default;

    void welcomeMessage() const override
    {
        std::cout << "Welcome to SavingsAccount!\n";
    }

    ~SavingsAccount() override = default;
};

int main()
{
    std::unique_ptr<Account> pAccount = std::make_unique<SavingsAccount>();
    pAccount->welcomeMessage(); // Calls SavingsAccount::welcomeMessage() at runtime
    return 0;
}
