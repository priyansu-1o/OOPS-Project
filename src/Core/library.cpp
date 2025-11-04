#include <bits/stdc++.h>
#include "library.hpp"
#include "../models/songClass.hpp"
using namespace std;

MusicLibrary::MusicLibrary() : totalSongs(0), totalDuration(0) {}

bool MusicLibrary::addSong(const Song& song) {
    for (const auto& existingSong : allSongs) {
        if (existingSong.getTitle() == song.getTitle()) {
            cout << "Song already added !!" << endl;
            return false;
        }
    }
    allSongs.push_back(song);
    refreshIndexes();
    updateStatistics();
    return true;
}

bool MusicLibrary :: removeSong(const string& songTitle){
    auto it = find_if(allSongs.begin(), allSongs.end(),
        [&songTitle](const Song& song) {
            return song.getTitle() == songTitle;
        });

    if(it != allSongs.end()){
        allSongs.erase(it);
        for (auto& playlist : playlists) {
            playlist.removeSong(songTitle);
        }
        refreshIndexes();
        updateStatistics();
        return true;
    }
    cout << "Song '" << songTitle << "' not found for removal!" << endl;
    return false;
}

Song* MusicLibrary::findSong(const string &title) {
    for (auto it = allSongs.begin(); it != allSongs.end(); ++it) {
        if (it->getTitle() == title) {
            return &(*it);
        }
    }
    cout << "Song not found !!" << endl;
    return nullptr;
}

vector<Song*> MusicLibrary :: searchSongs (const string& query){
    vector<Song*> results;
    string lowerQuery = query;
    transform(lowerQuery.begin(), lowerQuery.end(), lowerQuery.begin(), ::tolower);
    
    for (auto& song : allSongs) {
        string lowerTitle = song.getTitle();
        transform(lowerTitle.begin(), lowerTitle.end(), lowerTitle.begin(), ::tolower);
        
        string lowerArtist = song.getArtist();
        transform(lowerArtist.begin(), lowerArtist.end(), lowerArtist.begin(), ::tolower);
        
        string lowerGenre = song.getGenre();
        transform(lowerGenre.begin(), lowerGenre.end(), lowerGenre.begin(), ::tolower);
        
        if (lowerTitle.find(lowerQuery) != string::npos ||
            lowerArtist.find(lowerQuery) != string::npos ||
            lowerGenre.find(lowerQuery) != string::npos) {
            results.push_back(&song);
        }
    }
    return results;
}

void MusicLibrary::displayAllSongs() const {
    // Simple header approach
    cout << "\n🎵 MUSIC LIBRARY - ALL SONGS (" << allSongs.size() << " songs) 🎵" << endl;
    cout << string(120, '=') << endl;
    
    // Fixed column widths
    const int NUM_WIDTH = 4;
    const int TITLE_WIDTH = 40;
    const int ARTIST_WIDTH = 30;
    const int GENRE_WIDTH = 20;
    const int DURATION_WIDTH = 10;
    
    // Header
    cout << left 
         << setw(NUM_WIDTH) << "No." 
         << setw(TITLE_WIDTH) << "TITLE" 
         << setw(ARTIST_WIDTH) << "ARTIST" 
         << setw(GENRE_WIDTH) << "GENRE" 
         << setw(DURATION_WIDTH) << "DURATION" 
         << endl;
    cout << string(120, '-') << endl;
    
    if (allSongs.empty()) {
        cout << "No songs in the library" << endl;
    } else {
        for (size_t i = 0; i < allSongs.size(); i++) {
            const Song& song = allSongs[i];
            
            string title = song.getTitle();
            if (title.length() > TITLE_WIDTH - 2) 
                title = title.substr(0, TITLE_WIDTH - 3) + "...";
            
            string artist = song.getArtist();
            if (artist.length() > ARTIST_WIDTH - 2) 
                artist = artist.substr(0, ARTIST_WIDTH - 3) + "...";
            
            string genre = song.getGenre();
            if (genre.length() > GENRE_WIDTH - 2) 
                genre = genre.substr(0, GENRE_WIDTH - 3) + "...";
            
            cout << left 
                 << setw(NUM_WIDTH) << i + 1 
                 << setw(TITLE_WIDTH) << title 
                 << setw(ARTIST_WIDTH) << artist 
                 << setw(GENRE_WIDTH) << genre 
                 << setw(DURATION_WIDTH) << song.getDuration() 
                 << endl;
        }
    }
    
    cout << string(120, '=') << endl;
    cout << "Total Duration: " << totalDuration << " seconds" << endl;
    cout << endl;
}

void MusicLibrary::displayStatistics() const {
    cout << "=== Library Statistics ===" << endl;
    cout << "Total Songs: " << totalSongs << endl;
    cout << "Total Duration: " << totalDuration << " seconds" << endl;
    cout << "Unique Artists: " << songsByArtist.size() << endl;
    cout << "Unique Genres: " << songsByGenre.size() << endl;
}

vector<string> MusicLibrary::getAllArtists() const {
    vector<string> artists;
    artists.reserve(songsByArtist.size());
    for (const auto& pair : songsByArtist) {
        artists.push_back(pair.first);
    }
    return artists;
}

vector<string>MusicLibrary :: getAllGenres()const {
    vector<string>Genre;
    Genre.reserve(songsByGenre.size());
    for (const auto& pair : songsByGenre) {
        Genre.push_back(pair.first);
    }
    return Genre;
}

void MusicLibrary::refreshIndexes() {
    // Clear existing indexes
    songsByArtist.clear();
    songsByGenre.clear();
    
    // Rebuild indexes
    for (auto& song : allSongs) {
        // Index by artist
        songsByArtist[song.getArtist()].push_back(&song);
        
        // Index by genre
        songsByGenre[song.getGenre()].push_back(&song);
    }
}

void MusicLibrary::updateStatistics() {
    totalSongs = allSongs.size();
    
    // Calculate total duration
    totalDuration = 0;
    for (const auto& song : allSongs) {
        totalDuration = totalDuration + song.getDuration();
    }
}




