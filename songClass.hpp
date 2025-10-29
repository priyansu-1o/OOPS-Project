#ifndef SONGCLASS_HPP
#define SONGCLASS_HPP

#include <iostream>
#include <string>

using namespace std;

class Duration {
public:
    int min;
    int sec;
    
    // Constructor
    Duration(int m = 0, int s = 0);
    
    // Normalization function
    void normalize();
    
    // Operator overloads
    bool operator==(const Duration &other) const;
    bool operator!=(const Duration &other) const;
    
    // Friend functions for stream operators
    friend ostream& operator<<(ostream &os, const Duration &d);
    friend istream& operator>>(istream &is, Duration &d);
};

class Song {
protected:
    string title;
    string artist;
    string genre;
    Duration duration;
    string filepath;
    string id;

public:
    // Constructor
    Song();
    
    // Getters
    void getInfo();
    void displayInfo();
    string getId() const { return id; }
    string getTitle() const { return title; }
    string getArtist() const { return artist; }
    string getGenre() const { return genre; }
    Duration getDuration() const { return duration; }

    // Setters
    void setInfo();
    void setTitle(const string &t) { title = t; }
    void setArtist(const string &a) { artist = a; }
    void setGenre(const string &g) { genre = g; }
    void setDuration(Duration d) { duration = d; duration.normalize(); }

    // Operator Overloading
    bool operator==(const Song &other) const;
    bool operator!=(const Song &other) const;
    
    // Friend functions for stream operators
    friend ostream& operator<<(ostream &os, const Song &s);
    friend istream& operator>>(istream &is, Song &s);
};

#endif // SONGCLASS_HPP