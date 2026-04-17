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

// number_guess_human.cpp
// A simple number guessing game written step-by-step
#include <cstdlib> // for rand(), srand()
#include <ctime>   // for time()
#include <iostream>

int main()
{
    std::srand(static_cast<unsigned>(std::time(0))); // Seed RNG
    int secret = std::rand() % 100 + 1;              // Secret number (1–100)
    int guess;

    std::cout << "Guess the number (1–100): ";

    while (true)
    {
        std::cin >> guess;

        if (guess < secret)
        {
            std::cout << "Too low! Try again: ";
        }
        else if (guess > secret)
        {
            std::cout << "Too high! Try again: ";
        }
        else
        {
            std::cout << "Correct! You guessed it.\n";
            break;
        }
    }

    return 0;
}
