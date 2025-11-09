#ifndef MUSICLIBRARY_H
#define MUSICLIBRARY_H

#include "../models/songClass.hpp"
#include "playlist.hpp"
#include <vector>
#include <map>
#include <string>
using namespace std;

class MusicLibrary {
private:
    vector<Song> allSongs;
    vector<Playlist> playlists;
    
    // Indexes for fast searching
    map<string, vector<Song*>> songsByArtist;
    map<string, vector<Song*>> songsByGenre;
    
    // Statistics
    int totalSongs;
    int totalDuration;

public:
    MusicLibrary();

    bool addSong(const Song& song);
    void removeSong(int i);
    Song* findSong(const string& title);
    vector<Song*> findSongsByArtist(const string& artist);
    vector<Song*> findSongsByGenre(const string& genre);
    vector<Song*> searchSongs(const string& query);
    
    void displayAllSongs() const;
    void displayStatistics() const;
    vector<string> getAllArtists() const ;
    vector<string> getAllGenres() const;
    
    vector<Song> getAllSongs() const {return allSongs;};
    int getTotalSongCount() const {return totalSongs;};
    int getTotalDuration() const {return totalDuration;};
    
private:
    void refreshIndexes();
    void updateStatistics();
};

#endif