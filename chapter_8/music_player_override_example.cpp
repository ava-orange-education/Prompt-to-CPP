// music_player_override_example.cpp
// Example showing what happens when 'override' is missing in a derived class

#include <iostream>
#include <string> // Needed for std::string

class MusicPlayer
{
  public:
    virtual void play(const std::string &filename) const
    {
        std::cout << "Playing " << filename << " using generic player.\n";
    }
    virtual ~MusicPlayer() = default; // Virtual destructor for proper cleanup
};

class MP3Player : public MusicPlayer
{
  public:
    // Mistake: missing 'const', so this does not override the base version
    // The compiler treats this as a brand-new function
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
 
    return 0;
}