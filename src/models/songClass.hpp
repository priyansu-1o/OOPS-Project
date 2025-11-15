#ifndef SONGCLASS_HPP
#define SONGCLASS_HPP
#include "json.hpp"
#include <bits/stdc++.h>
#include <string>
using json = nlohmann::json;
using namespace std;


class Song {
protected:
    string title;
    string artist;
    string genre;
    string filepath;
    string id;
    int duration;

public:
    // Constructors
    Song();
    Song(const string &t, const string &a, const string &g, int d);
    Song(int x);  // Constructor that prompts for input (x is just a flag)
    
    // Getters
    void displayInfo();
    string getId() const { return id; }
    string getTitle() const { return title; }
    string getArtist() const { return artist; }
    string getGenre() const { return genre; }
    string getfilepath()const{return filepath;}
    int getDuration() const { return duration; }

    // Setters
    void setInfo();
    void setTitle(const string &t) { title = t; }
    void setArtist(const string &a) { artist = a; }
    void setGenre(const string &g) { genre = g; }
    void setDuration(int d) { duration = d;}

    // Operator Overloading
    bool operator==(const Song &other) const;
    bool operator!=(const Song &other) const;

    //JSON_config
    friend bool jsonify(vector<Song>& libraryExample);
    friend vector<Song> stringify();
    
    // Friend functions for stream operators
    friend ostream& operator<<(ostream &os, const Song &s);
    friend istream& operator>>(istream &is, Song &s);

    friend void to_json(json& j, const Song& s);
    friend void from_json(const json& j, Song& s);
};

#endif // SONGCLASS_HPP