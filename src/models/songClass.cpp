#include "songClass.hpp"
#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

// Duration class implementations
Duration::Duration(int s) : sec(s) {
    // No need to normalize, store as seconds only
}

void Duration::normalize() {
    // No-op: we store everything in seconds
}

bool Duration::operator==(const Duration &other) const {
    return sec == other.sec;
}

bool Duration::operator!=(const Duration &other) const {
    return !(*this == other);
}

ostream& operator<<(ostream &os, const Duration &d) {
    os << d.sec; // Output seconds only
    return os;
}

istream& operator>>(istream &is, Duration &d) {
    is >> d.sec; // Input seconds only
    return is;
}

// Song class implementations
Song::Song() {
    // setInfo();
}

void Song::getInfo() {
    displayInfo();
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