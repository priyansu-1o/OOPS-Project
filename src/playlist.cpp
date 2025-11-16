#include<conio.h>
#include "playlist.hpp"
#include "models/songClass.hpp"
using namespace std;
Playlist::Playlist():playlistName("Untitled Playlist"){}
Playlist::Playlist(string name):playlistName(name){}
void Playlist::addSong(const Song &song){
    songs.push_back(song);
}
void Playlist::removeSong(int i){
    songs.erase(songs.begin()+i);
}
int Playlist::totalduration(){
    int totalSec=0;
    for(const auto &song:songs){
        totalSec += song.getDuration();
    }
    return totalSec;
}
// Required headers: <iostream>, <vector>, <string>, <conio.h>, <stdlib.h>

int Playlist::displaySongs() {
    if (songs.empty()) {
        system("cls");
        std::cout << "\n🎵 Playlist: " << playlistName << "\n";
        std::cout << "-------------------------\n";
        std::cout << "No songs available.\n";
        std::cout << "-------------------------\n";
        std::cout << "Press any key to return...\n";
        _getch();
        return -1; // Return -1 as no song can be selected
    }

    int currentIndex = 0;
    char input;

    while (true) {
        system("cls"); // Clears the console screen

        std::cout << "\n🎵 Playlist: " << playlistName << "\n";
        std::cout << "-----------------------------------------------------\n";

        // Iterate through the songs and display them
        for (size_t i = 0; i < songs.size(); ++i) {
            if (i == currentIndex) {
                std::cout << "-> "; // Selector for the highlighted song
            } else {
                std::cout << "   ";
            }
            std::cout << songs[i] << "\n"; // Assumes Song has an operator<< overload
        }

        std::cout << "-----------------------------------------------------\n";
        int total = totalduration();
        std::cout << "Total Duration: " << total << "s\n";
        std::cout << "Use 'w'/'s' to navigate, 'Enter' to select, 'q' to back.\n";

        input = _getch(); // Get a single character without waiting for Enter

        switch (input) {
            case 'w':
            case 'W':
                if (currentIndex > 0) {
                    currentIndex--;
                } else {
                    currentIndex = songs.size() - 1; // Wrap to the bottom
                }
                break;
            case 's':
            case 'S':
                if (currentIndex < songs.size() - 1) {
                    currentIndex++;
                } else {
                    currentIndex = 0; // Wrap to the top
                }
                break;
            case '\r': // The Enter key
                return currentIndex; // Return the index of the selected song
            case 'q':
            case 'Q':
                return -1; // Return -1 to indicate user backed out
        }
    }
}

Playlist Playlist::operator+(const Playlist &other) const{
   Playlist merged("Merged: " + playlistName + " + " + other.playlistName);
    merged.songs = songs; // copy current songs
    merged.songs.insert(merged.songs.end(), other.songs.begin(), other.songs.end());
    return merged;
}
std::ostream& operator<<(std::ostream &os, const Playlist &p) {
    os << "[Playlist] " << p.playlistName << " (" << p.songs.size() << " songs)";
    return os;
}
void Playlist::changename(string n)
{
    playlistName=n;
}
string Playlist::PLname()
{
    return playlistName;
}
vector<Song> Playlist::want_playlist_songs()
{
    return songs;
}