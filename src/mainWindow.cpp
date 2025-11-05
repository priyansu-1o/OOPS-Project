
#include <iostream>
#include <windows.h>
#include <string>
#include <thread>
#include <conio.h>  
#include <chrono>
#include <mmsystem.h>
using namespace std;
#pragma comment(lib, "winmm.lib") 

void moveCursorToHome() {
    COORD coord = {0, 0};
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
class Song
{
    public:
        std::string filePath; 

        
        Song(const std::string& path) : filePath(path) 
        {
            std::cout << "Song object created with path: " << filePath << std::endl;
        }
};

class SongPlayer {
public:
    void playSong(const Song& song) {
        std::string command = "open \"" + song.filePath + "\" type mpegvideo alias mySong";
        mciSendString(command.c_str(), NULL, 0, NULL);
        mciSendString("play mySong", NULL, 0, NULL);
   
    }

    void pauseSong() {
        mciSendString("pause mySong", NULL, 0, NULL);
      
    }

    void resumeSong() {
        mciSendString("resume mySong", NULL, 0, NULL);
     
    }

    void stopSong() {
        mciSendString("stop mySong", NULL, 0, NULL);
        mciSendString("close mySong", NULL, 0, NULL);
     
    }
};
class interfacemusicplayer
{
      
        public:
                    
void printCentered(const string &text, int width = 166) {
    int padding = (width - (int)text.size()) / 2;
    if (padding > 0)
        cout << string(padding, ' ') << text << endl;
    else
        cout << text << endl;
}

void showProgressBar(int current, int total, int width = 30) {
    int pos = (current * width) / total;
    string bar = "[";
    for (int i = 0; i < width; ++i)
        bar += (i < pos ? "#" : "_");
    bar += "] " + to_string(current) + "s / " + to_string(total) + "s";

    // Move cursor to start of line (for smoother animation)
    cout << "\r";
    printCentered(bar);
    cout.flush();
}
 
    void playUI(const string &title, const string &artist, int duration, Song s) {
        bool paused = false, stopped = false;
        bool prevPauseState = false;
        double elapsed = 0.0;
        SongPlayer sp;

        sp.playSong(s);
        auto start = chrono::steady_clock::now();

        // Print enough newlines to clear the screen once
        for(int i = 0; i < 40; ++i) cout << endl;

        while (elapsed <= duration) {
            moveCursorToHome();
            printCentered("=========================================");
            printCentered("// NOW PLAYING //");
            printCentered("-----------------------------------------");
            printCentered("Title: " + title);
            printCentered("Artist: " + artist);
            printCentered("Duration: " + to_string(duration) + " seconds");
            printCentered("-----------------------------------------");
            printCentered(paused ? "::> Paused..." : "::> Playing...");
            showProgressBar(static_cast<int>(elapsed), duration);
            printCentered("-----------------------------------------");
            printCentered("[P] Pause   [R] Resume   [S] Stop");
            printCentered("-----------------------------------------");

            // Handle keypress
            if (_kbhit()) {
                char key = toupper(_getch());
                if (key == 'P') paused = true;
                else if (key == 'R') paused = false;
                else if (key == 'S') { stopped = true; break; }
            }

            // Handle pause/resume transitions
            if (paused && !prevPauseState) {
                sp.pauseSong();
            }
            if (!paused && prevPauseState) {
                sp.resumeSong();
                start = chrono::steady_clock::now();
            }

            // Update elapsed only if not paused
            if (!paused) {
                auto now = chrono::steady_clock::now();
                chrono::duration<double> delta = now - start;
                elapsed += delta.count();
                start = now;
            }

            Sleep(200);
            prevPauseState = paused;
        }

        sp.stopSong();
        printCentered("Playback finished.");
    }
};
int main()
{
    interfacemusicplayer i;
     Song s("C:\\Users\\arpit\\Downloads\\Jhol.mp3"); 
    i.playUI("Jhol","Annural khalid & Maanu ",240,s);
    int b;
    cin>>b;
    return 0;
}
