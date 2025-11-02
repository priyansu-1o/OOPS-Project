#include "songClass.hpp"
#include <iostream>
#include <string>
#include <iomanip>

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
       << " | Duration: " << s.duration;
    return os;
}

istream& operator>>(istream &is, Song &s) {
    cout << "Enter title: ";
    getline(is >> ws, s.title);
    cout << "Enter artist: ";
    getline(is >> ws, s.artist);
    cout << "Enter genre: ";
    getline(is >> ws, s.genre);
    cout << "Enter duration (format: minutes:seconds or minutes seconds): ";
    cin>>s.duration;
    return is;
}