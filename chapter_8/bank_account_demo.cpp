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
