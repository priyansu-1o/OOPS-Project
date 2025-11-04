#ifndef PLAYLIST_HPP
#define PLAYLIST_HPP
#include<bits/stdc++.h>
#include "../models/songClass.hpp"
using namespace std;
class Playlist{
    vector<Song> songs;
    string playlistName;
    public:
    Playlist();
    Playlist(string name);
    string PLname();
    void changename(string n);
    void addSong(const Song &song);
    void removeSong(const string &songTitle);
    int totalduration();
    void displaySongs();
    Playlist operator+(const Playlist &other) const;
    friend ostream& operator<<(ostream &os,const Playlist &pl);
};
#endif