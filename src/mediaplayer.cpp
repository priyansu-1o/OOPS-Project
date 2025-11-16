#include "MediaPlayer.hpp"
#include <iostream>
#include <windows.h>
#include <thread>
#include <conio.h>
#include <chrono>
#include <mmsystem.h>
#include "models\songClass.hpp"
#include "playlist.hpp"
#include "library.hpp"

#pragma comment(lib, "winmm.lib")

// --- Utility Function Definitions ---
void moveCursorToHome() {
    COORD coord = {0, 0};
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

// --- SongPlayer Member Function Definitions ---
void SongPlayer::playSong(const Song& song) {
    std::string command = "open \"" + song.getfilepath() + "\" type mpegvideo alias mySong";
    mciSendString(command.c_str(), NULL, 0, NULL);
    mciSendString("play mySong", NULL, 0, NULL);
}

void SongPlayer::pauseSong() {
    mciSendString("pause mySong", NULL, 0, NULL);
}

void SongPlayer::resumeSong() {
    mciSendString("resume mySong", NULL, 0, NULL);
}

void SongPlayer::stopSong() {
    mciSendString("stop mySong", NULL, 0, NULL);
    mciSendString("close mySong", NULL, 0, NULL);
}

// --- interfacemusicplayer Member Function Definitions ---
interfacemusicplayer::interfacemusicplayer(const Song& sa) : s(sa), paused(false), prevPauseState(false), elapsed(0.0) {
    runUI(); // Constructor now calls the main UI loop
}

void interfacemusicplayer::printCentered(const std::string& text, int width) {
    int padding = (width - text.length()) / 2;
    if (padding > 0)
        std::cout << std::string(padding, ' ') << text << std::endl;
    else
        std::cout << text << std::endl;
}

void interfacemusicplayer::showProgressBar(int current, int total, int width) {
    if (total == 0) return; // Avoid division by zero
    int pos = (current * width) / total;
    std::string bar = "[";
    for (int i = 0; i < width; ++i)
        bar += (i < pos ? "#" : "_");
    bar += "] " + std::to_string(current) + "s / " + std::to_string(total) + "s";

    std::cout << "\r"; // Move cursor to start of line for smooth animation
    printCentered(bar);
    std::cout.flush();
}

void interfacemusicplayer::runUI() {
    sp.playSong(s);
    auto start = std::chrono::steady_clock::now();
    
    // Clear the screen by printing newlines
    for(int i = 0; i < 40; ++i) std::cout << std::endl;

    while (elapsed <= s.getDuration()) {
        moveCursorToHome();
        printCentered("=========================================");
        printCentered("// NOW PLAYING //");
        printCentered("-----------------------------------------");
        printCentered("Title: " + s.getTitle());
        printCentered("Artist: " + s.getArtist());
        printCentered("Duration: " + std::to_string(s.getDuration()) + " seconds");
        printCentered("-----------------------------------------");
        printCentered(paused ? "::> Paused..." : "::> Playing...");
        showProgressBar(static_cast<int>(elapsed), s.getDuration());
        printCentered("-----------------------------------------");
        printCentered("[P] Pause | [R] Resume | [S] Stop & Exit");
        printCentered("-----------------------------------------");

        if (_kbhit()) {
            char key = toupper(_getch());
            if (key == 'P') paused = true;
            else if (key == 'R') paused = false;
            else if (key == 'S') break;
        }

        if (paused && !prevPauseState) {
            sp.pauseSong();
        }
        if (!paused && prevPauseState) {
            sp.resumeSong();
            start = std::chrono::steady_clock::now(); // Reset timer on resume
        }

        if (!paused) {
            auto now = std::chrono::steady_clock::now();
            std::chrono::duration<double> delta = now - start;
            elapsed += delta.count();
            start = now;
        }

        Sleep(200);
        prevPauseState = paused;
    }

    sp.stopSong();
    printCentered("Playback finished.");
    Sleep(1000); // Pause briefly before returning
}

