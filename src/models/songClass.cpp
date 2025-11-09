#include "songClass.hpp"
#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;

// Song class implementations
Song::Song() {
    setInfo();
}

void Song::displayInfo() {
    cout << *this << endl;
}

void Song::setInfo() {
    cin >> *this;
}

bool Song::operator==(const Song &other) const {
    return id == other.id || (title == other.title && artist == other.artist);
}

bool Song::operator!=(const Song &other) const {
    return !(*this == other);
}

ostream& operator<<(ostream &os, const Song &s) {
    os << "[Song] '" << s.title << "' by " << s.artist
       << " | Genre: " << s.genre
       << " | Duration: " << s.duration << "s";
    return os;
}

istream& operator>>(istream &is, Song &s) {
    cout << "Enter title: ";
    getline(is >> ws, s.title);
    cout << "Enter artist: ";
    getline(is >> ws, s.artist);
    cout << "Enter genre: ";
    getline(is >> ws, s.genre);
    cout << "Enter duration (in seconds): ";
    is >> s.duration;
    return is;
}

void to_json(json& j, const Song& s) {
    j = json{
        {"title", s.title},
        {"artist", s.artist},
        {"genre", s.genre},
        {"filepath", s.filepath},
        {"id", s.id},
        {"duration", s.duration}
    };
}

void from_json(const json& j, Song& s) {
    j.at("title").get_to(s.title);
    j.at("artist").get_to(s.artist);
    j.at("genre").get_to(s.genre);
    j.at("filepath").get_to(s.filepath);
    j.at("id").get_to(s.id);
    j.at("duration").get_to(s.duration);
}

bool jsonify(vector<Song>& libraryExample){
    try {
        json j = libraryExample;
        
        ofstream file("song.json");
        file << j.dump(4);
        file.close();
        
        cout << "\n✅ Saved " << libraryExample.size() << " songs to song.json" << endl;
        return true;
    }
    catch (const exception& e) {
        cerr << "❌ Error: " << e.what() << endl;
        return false;
    }
}

vector<Song> stringify(){
    ifstream input_file("song.json");
    if (!input_file.is_open()) {
        cerr << "❌ Cannot open song.json for reading" << endl;
        return vector<Song>();
    }
    
    try {
        json loaded_json;
        input_file >> loaded_json;
        input_file.close();
        
        auto loaded_songs = loaded_json.get<vector<Song>>();
        return loaded_songs;
    }
    catch (const exception& e) {
        cerr << "❌ Error parsing JSON: " << e.what() << endl;
        input_file.close();
        return vector<Song>();
    }
}