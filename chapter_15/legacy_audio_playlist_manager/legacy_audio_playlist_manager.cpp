// legacy_audio_playlist_manager.cpp
// A legacy audio playlist manager using manual memory management and loops
// (C++98)
#include <iostream>
#include <string>
#include <vector>

// A simple structure to represent a music track
class Song {
public:
  std::string title;
  int durationSeconds;

  Song(std::string t, int d) : title(t), durationSeconds(d) {}
};

// The manager that handles the playlist memory manually
class Playlist {
private:
  std::vector<Song *> tracks; // Raw pointers - risky in modern C++!

public:
  // Manual Cleanup (Required in C++98)
  ~Playlist() {
    for (size_t i = 0; i < tracks.size(); ++i) {
      delete tracks[i];
    }
    std::cout << "Playlist memory cleared manually." << "\n";
  }

  void addSong(std::string title, int duration) {
    Song *newSong = new Song(title, duration);
    tracks.push_back(newSong);
  }

  // Manual loop for filtering (The "Old Way")
  void showLongSongs(int minSeconds) {
    std::cout << "Songs over " << minSeconds << " seconds:" << "\n";
    std::vector<Song *>::iterator it;
    for (it = tracks.begin(); it != tracks.end(); ++it) {
      if ((*it)->durationSeconds > minSeconds) {
        std::cout << " - " << (*it)->title << " (" << (*it)->durationSeconds
                  << "s)" << "\n";
      }
    }
  }
};

int main() {
  Playlist myMix;
  myMix.addSong("Stairway to Heaven", 480);
  myMix.addSong("Yesterday", 125);
  myMix.addSong("Bohemian Rhapsody", 355);

  myMix.showLongSongs(180);

  return 0;
}