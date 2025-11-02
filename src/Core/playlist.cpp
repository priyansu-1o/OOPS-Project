#include "playlist.hpp"
#include "../models/songClass.hpp"
using namespace std;
Playlist::Playlist():playlistName("Untitled Playlist"){}
Playlist::Playlist(string name):playlistName(name){}
void Playlist::addSong(const Song &song){
    songs.push_back(song);
}
void Playlist::removeSong(const string &songTitle){
    auto it = remove_if(songs.begin(), songs.end(), [&](const Song &s) {
        return s.getTitle() == songTitle;
    });
    if (it != songs.end()) {
        songs.erase(it, songs.end());
    } else {
        cout << "Song with title \"" << songTitle << "\" not found in the playlist.\n";
    }
}
int Playlist::totalduration(){
    int totalSec=0;
    for(const auto &song:songs){
        totalSec += song.getDuration();
    }
    return totalSec;
}
void Playlist::displaySongs() {
    std::cout << "\n🎵 Playlist: " << playlistName << "\n";
    std::cout << "-------------------------\n";
    if (songs.empty()) {
        std::cout << "No songs available.\n";
        return;
    }
    for (const auto &song : songs) {
        std::cout << song << "\n"; // Uses Song's operator<<
    }

    int total=totalduration();
    std::cout << "-------------------------\n";
    std::cout << "Total Duration: " << total <<"s\n";
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