#ifndef MEDIAPLAYER_HPP
#define MEDIAPLAYER_HPP

#include <iostream>
#include <windows.h>
#include <string>
#include <thread>
#include <conio.h>  
#include <chrono>
#include <mmsystem.h>
#include "models\songClass.hpp"
#include "Core\playlist.hpp"
#include "Core\library.hpp"

// Forward declaration for utility functions if needed
void moveCursorToHome();

// --- SongPlayer Class Declaration ---
// This class handles the low-level MCI commands for audio playback.
class SongPlayer {
public:
    void playSong(const Song& song);
    void pauseSong();
    void resumeSong();
    void stopSong();
};

// --- interfacemusicplayer Class Declaration ---
// This class manages the user interface for the currently playing song.
class interfacemusicplayer {
private:
    Song s;
    SongPlayer sp;
    bool paused;
    bool prevPauseState;
    double elapsed;

    // Private helper methods for the UI
    void printCentered(const std::string& text, int width = 166);
    void showProgressBar(int current, int total, int width = 30);
    void runUI(); // The main loop for the UI

public:
    // Constructor takes a Song object and starts the UI
    interfacemusicplayer(const Song& sa);
};


#endif // MEDIAPLAYER_HPP