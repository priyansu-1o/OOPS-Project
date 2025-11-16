#ifndef PLAYLIST_HPP
#define PLAYLIST_HPP
#include<bits/stdc++.h>
#include "models/songClass.hpp"
using namespace std;
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