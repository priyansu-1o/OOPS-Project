#include <bits/stdc++.h>
#include "library.hpp"
#include "models/songClass.hpp"
#include<conio.h>
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

void MusicLibrary :: removeSong(int i){
            allSongs.erase(allSongs.begin()+i);
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
int MusicLibrary::displayAllSongs() const {
    int selectedIndex = 0;
    const int pageSize = 15; // Number of songs to show per "page"
    int currentPage = 0;
    int totalPages = max(1, (int)(allSongs.size() + pageSize - 1) / pageSize); // Ensure at least 1 page

    while (true) {
        system("cls");
        int startIdx = currentPage * pageSize;
        int endIdx = min(startIdx + pageSize, (int)allSongs.size());
        
        // Display header
        const int totalWidth = 155;
        const int contentWidth = 120;
        
        cout << string((totalWidth - contentWidth) / 2, ' ') 
             << "+" << string(contentWidth - 2, '-') << "+" << endl;
        
        cout << string((totalWidth - contentWidth) / 2, ' ') 
             << "|" << string(contentWidth - 2, ' ') << "|" << endl;
        
        string header = "MUSIC LIBRARY - ALL SONGS (" + to_string(allSongs.size()) + " songs) - Page " + 
                       to_string(currentPage + 1) + "/" + to_string(totalPages);
        int headerPadding = (contentWidth - 2 - header.length()) / 2;
        cout << string((totalWidth - contentWidth) / 2, ' ') 
             << "|" << string(headerPadding, ' ') << header 
             << string(contentWidth - 2 - headerPadding - header.length(), ' ') << "|" << endl;
        
        cout << string((totalWidth - contentWidth) / 2, ' ') 
             << "|" << string(contentWidth - 2, ' ') << "|" << endl;
        cout << string((totalWidth - contentWidth) / 2, ' ') 
             << "+" << string(contentWidth - 2, '-') << "+" << endl;
        
        // Column headers
        const int numWidth = 6;
        const int titleWidth = 30;
        const int artistWidth = 25;
        const int genreWidth = 20;
        const int durationWidth = 12;
        
        string headers = "| " 
                       + string((numWidth - 3) / 2, ' ') + "No." + string(numWidth - 3 - (numWidth - 3) / 2, ' ')
                       + " | "
                       + string((titleWidth - 5) / 2, ' ') + "TITLE" + string(titleWidth - 5 - (titleWidth - 5) / 2, ' ')
                       + " | "
                       + string((artistWidth - 6) / 2, ' ') + "ARTIST" + string(artistWidth - 6 - (artistWidth - 6) / 2, ' ')
                       + " | "
                       + string((genreWidth - 5) / 2, ' ') + "GENRE" + string(genreWidth - 5 - (genreWidth - 5) / 2, ' ')
                       + " | "
                       + string((durationWidth - 8) / 2, ' ') + "DURATION" + string(durationWidth - 8 - (durationWidth - 8) / 2, ' ')
                       + " |";
        
        cout << string((totalWidth - headers.length()) / 2, ' ') << headers << endl;
        cout << string((totalWidth - contentWidth) / 2, ' ') 
             << "+" << string(contentWidth - 2, '-') << "+" << endl;
        
        // Display songs for current page
        if (allSongs.empty()) {
            string noSongs = "No songs in the library";
            int padding = (contentWidth - 2 - noSongs.length()) / 2;
            cout << string((totalWidth - contentWidth) / 2, ' ') 
                 << "|" << string(padding, ' ') << noSongs 
                 << string(contentWidth - 2 - padding - noSongs.length(), ' ') << "|" << endl;
        } else {
            for (int i = startIdx; i < endIdx; i++) {
                const Song& song = allSongs[i];
                
                string title = song.getTitle();
                if (title.length() > titleWidth - 2) 
                    title = title.substr(0, titleWidth - 3) + "...";
                
                string artist = song.getArtist();
                if (artist.length() > artistWidth - 2) 
                    artist = artist.substr(0, artistWidth - 3) + "...";
                
                string genre = song.getGenre();
                if (genre.length() > genreWidth - 2) 
                    genre = genre.substr(0, genreWidth - 3) + "...";
                
                string duration = to_string(song.getDuration());
                string number = to_string(i + 1) + ".";
                
                string row = "| "
                           + string((numWidth - number.length()) / 2, ' ') + number + string(numWidth - number.length() - (numWidth - number.length()) / 2, ' ')
                           + " | "
                           + string((titleWidth - title.length()) / 2, ' ') + title + string(titleWidth - title.length() - (titleWidth - title.length()) / 2, ' ')
                           + " | "
                           + string((artistWidth - artist.length()) / 2, ' ') + artist + string(artistWidth - artist.length() - (artistWidth - artist.length()) / 2, ' ')
                           + " | "
                           + string((genreWidth - genre.length()) / 2, ' ') + genre + string(genreWidth - genre.length() - (genreWidth - genre.length()) / 2, ' ')
                           + " | "
                           + string((durationWidth - duration.length()) / 2, ' ') + duration + string(durationWidth - duration.length() - (durationWidth - duration.length()) / 2, ' ')
                           + " |";
                
                // Highlight selected song with arrow
                if (i == selectedIndex) {
                    cout << string((totalWidth - row.length()) / 2 - 3, ' ') 
                         << "-> " << row << endl;
                } else {
                    cout << string((totalWidth - row.length()) / 2, ' ') << row << endl;
                }
            }
        }
        
        // Footer with instructions
        cout << string((totalWidth - contentWidth) / 2, ' ') 
             << "+" << string(contentWidth - 2, '-') << "+" << endl;
        
        string footer = "Total Duration: " + to_string(totalDuration) + " seconds";
        int footerPadding = (contentWidth - 2 - footer.length()) / 2;
        cout << string((totalWidth - contentWidth) / 2, ' ') 
             << "|" << string(footerPadding, ' ') << footer 
             << string(contentWidth - 2 - footerPadding - footer.length(), ' ') << "|" << endl;
        
        string instructions = "W/S: Navigate | A/D: Change Page | Enter: Select | Q: Quit";
        int instPadding = (contentWidth - 2 - instructions.length()) / 2;
        cout << string((totalWidth - contentWidth) / 2, ' ') 
             << "|" << string(instPadding, ' ') << instructions 
             << string(contentWidth - 2 - instPadding - instructions.length(), ' ') << "|" << endl;
        
        cout << string((totalWidth - contentWidth) / 2, ' ') 
             << "+" << string(contentWidth - 2, '-') << "+" << endl;
        
        // Get user input
        char c = _getch();
        
        if (c == 'w' || c == 'W') { // Move up - WITH LOOPING
            if (selectedIndex > 0) {
                selectedIndex--;
            } else {
                // Loop to bottom when at top
                selectedIndex = allSongs.size() - 1;
                currentPage = totalPages - 1; // Go to last page
            }
            
            // If we move above current page, change page
            if (selectedIndex < currentPage * pageSize && currentPage > 0) {
                currentPage--;
            }
        }
        else if (c == 's' || c == 'S') { // Move down - WITH LOOPING
            if (selectedIndex < allSongs.size() - 1) {
                selectedIndex++;
            } else {
                // Loop to top when at bottom
                selectedIndex = 0;
                currentPage = 0; // Go to first page
            }
            
            // If we move beyond current page, change page
            if (selectedIndex >= (currentPage + 1) * pageSize && currentPage < totalPages - 1) {
                currentPage++;
            }
        }
        else if (c == 'a' || c == 'A') { // Previous page - WITH LOOPING
            if (currentPage > 0) {
                currentPage--;
            } else {
                // Loop to last page when at first page
                currentPage = totalPages - 1;
            }
            selectedIndex = currentPage * pageSize; // Select first item on new page
        }
        else if (c == 'd' || c == 'D') { // Next page - WITH LOOPING
            if (currentPage < totalPages - 1) {
                currentPage++;
            } else {
                // Loop to first page when at last page
                currentPage = 0;
            }
            selectedIndex = currentPage * pageSize; // Select first item on new page
        }
        else if(c==13){
            return selectedIndex;
        }
        else if (c == 'q' || c == 'Q') { // Quit
            break;
        }
    }
    return -1;
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






