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
// FinalSpecifierExample.cpp
// Demonstrates how the 'final' specifier prevents further inheritance

#include <iostream>
#include <string>

class MusicPlayer final // No other class can inherit from this
{
  public:
    void play(const std::string &filename) const
    {
        std::cout << "Playing " << filename << " using MusicPlayer\n";
    }
};

int main()
{
    MusicPlayer player;
    player.play("song.mp3");
    return 0;
}