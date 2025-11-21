#ifndef PLAYLIST_HPP
#define PLAYLIST_HPP
#include<bits/stdc++.h>
#include "models/songClass.hpp"
using namespace std;

// Template function to calculate total duration of any container with getDuration()
template<typename Container>
int calculateTotalDuration(const Container& items) {
    int totalSec = 0;
    for (const auto& item : items) {
        totalSec += item.getDuration();
    }
    return totalSec;
}
class Playlist{
    vector<Song> songs;
    string playlistName;
    public:
    Playlist();
    Playlist(string name);
    void changename(string n);
    string PLname();
    vector<Song> want_playlist_songs();
    void addSong(const Song &song);
    void removeSong(int i);
    int totalduration();
    int displaySongs();
    Playlist operator+(const Playlist &other) const;
    friend ostream& operator<<(ostream &os,const Playlist &pl);
};
#endif