#include "Core/playlist.hpp"
#include  "models/songClass.hpp"
#include <iostream>
using namespace std;

    // cout << "=== TEST CASE 5: Empty and Whitespace Inputs ===" << endl;
    
    // cout << "Testing with empty inputs (just press enter):" << endl;
    // Song song1;
    // cout << "Result: " << song1 << endl;
    
    // cout << "\nTesting with whitespace-only inputs:" << endl;
    // Song song2;
    // cout << "Result: " << song2 << endl;
    
    // return 0;

int main() {
    Song s1;
    cin >> s1;
    Song s2;
    cin>>s2;
    Song s3;
    cin>>s3;
    Playlist chill("Chill Vibes");
    chill.addSong(s1);
    chill.addSong(s3);
    chill.displaySongs();

    Playlist workout("Workout Mix");
    workout.addSong(s2);
    workout.displaySongs();

    Playlist combined = chill + workout;
    std::cout << combined << std::endl;
    combined.displaySongs();

    chill.removeSong("Perfect");
    chill.displaySongs();

    return 0;
}

