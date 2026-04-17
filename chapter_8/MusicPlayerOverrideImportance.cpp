// MusicPlayerOverrideExample.cpp
// Example demonstrating the importance of the 'override' specifier in C++
#include <iostream>
class MusicPlayer
{
  public:
    virtual void play(const std::string &filename) const
    {
        std::cout << "Playing " << filename << " using generic player.\n";
    }
};

class MP3Player : public MusicPlayer
{
  public:
    // Mistake: missing 'const', not an override
    void play(const std::string &filename)
    {
        std::cout << "Playing " << filename << " using MP3Player.\n";
    }
};

int main()
{
    MusicPlayer *player = new MP3Player();
    player->play("track01.mp3"); // Calls base version, not derived
    delete player;
}
