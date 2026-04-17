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