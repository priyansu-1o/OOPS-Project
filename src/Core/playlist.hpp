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
    Playlist(string name):playlistName(name){}
    void addSong(const Song &song);
    void removeSong(const string &songTitle);
    void displaySongs() const;
    int totalduration();
    Playlist operator+(const Playlist &other) const;
    friend ostream& operator<<(ostream &os,const Playlist &pl);

};
#endif