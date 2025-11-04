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

// void MusicLibrary :: createPlaylist(const string& name, const string& desciption = ""){
//     for (auto& playlist : playlists) {
//         if (playlist.getName() == name) {
//             cout << "Playlist '" << name << "' already exists!" << endl;
//             return;
//         }
//     }
//     Playlist newPlaylist(name);
//     playlists.push_back(newPlaylist);
//     cout << "Playlist '" << name << "' created successfully!" << endl;
// }

void MusicLibrary :: displayAllSongs() const {
    const int totalCols = 150;
    const int boxWidth = 140;

    int leftPadding = (totalCols - boxWidth) / 2;
    int totalRows = 40;
    
    int boxHeight = allSongs.size() + 8;
    int topPadding = (totalRows - boxHeight) / 2;

    for (int i = 0; i < topPadding; i++)
        cout << endl;

    // Top border
    cout << string(leftPadding, ' ') << " " << string(boxWidth - 2, '_') << " " << endl;

    // Header
    string header = "🎵 MUSIC LIBRARY - ALL SONGS (" + to_string(allSongs.size()) + " songs) 🎵";
    int headerPadding = (boxWidth - 2 - header.length()) / 2;
    cout << string(leftPadding, ' ')
         << "|" << string(headerPadding, ' ') << header
         << string(boxWidth - 2 - headerPadding - header.length(), ' ') << "|" << endl;

    // Column headers with formatting
    string headers = string(4, ' ') + 
                    string(35, ' ') + "TITLE" + string(35, ' ') + " | " +
                    string(25, ' ') + "ARTIST" + string(25, ' ') + " | " +
                    string(15, ' ') + "GENRE" + string(15, ' ') + " | " +
                    "DURATION";
    cout << string(leftPadding, ' ') 
         << "|" << string(boxWidth - 2, '-') << "|" << endl;
    cout << string(leftPadding, ' ')
         << "|" << headers << "|" << endl;
    cout << string(leftPadding, ' ') 
         << "|" << string(boxWidth - 2, '-') << "|" << endl;

    if (allSongs.empty()) {
        string noSongs = "No songs in the library";
        int noSongsPadding = (boxWidth - 2 - noSongs.length()) / 2;
        cout << string(leftPadding, ' ')
             << "|" << string(noSongsPadding, ' ') << noSongs
             << string(boxWidth - 2 - noSongsPadding - noSongs.length(), ' ') << "|" << endl;
    } else {
        for (size_t i = 0; i < allSongs.size(); i++) {
            const Song& song = allSongs[i];
            
            // Format each field with fixed widths
            string title = song.getTitle();
            if (title.length() > 40) title = title.substr(0, 37) + "...";
            
            string artist = song.getArtist();
            if (artist.length() > 30) artist = artist.substr(0, 27) + "...";
            
            string genre = song.getGenre();
            if (genre.length() > 20) genre = genre.substr(0, 17) + "...";
            
            string duration = to_string(song.getDuration());
            
            // Create formatted line
            string songLine = to_string(i + 1) + ". " +
                            string(40 - title.length()/2, ' ') + title + 
                            " | " + string(30 - artist.length()/2, ' ') + artist +
                            " | " + string(20 - genre.length()/2, ' ') + genre +
                            " | " + string(8 - duration.length()/2, ' ') + duration;
            
            cout << string(leftPadding, ' ')
                 << "|" << songLine 
                 << string(boxWidth - 2 - songLine.length(), ' ') << "|" << endl;
        }
    }

    // Footer
    cout << string(leftPadding, ' ') 
         << "|" << string(boxWidth - 2, '-') << "|" << endl;
    
    string footer = "Total Duration: " + to_string(totalDuration);
    int footerPadding = (boxWidth - 2 - footer.length()) / 2;
    cout << string(leftPadding, ' ')
         << "|" << string(footerPadding, ' ') << footer
         << string(boxWidth - 2 - footerPadding - footer.length(), ' ') << "|" << endl;

    cout << string(leftPadding, ' ') << "|" << string(boxWidth - 2, '_') << "|" << endl;
    
    for (int i = 0; i < 3; i++)
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




