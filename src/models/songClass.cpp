#include "songClass.hpp"
#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

// Duration class implementations
Duration::Duration(int m, int s) : min(m), sec(s) {
    normalize();
}

void Duration::normalize() {
    if (sec >= 60 || sec < 0) {
        min += sec / 60;
        sec = sec % 60;
        
        // Handle negative seconds
        if (sec < 0) {
            sec += 60;
            min -= 1;
        }
    }
    
    // Handle negative minutes
    if (min < 0) {
        min = 0;
        sec = 0;
    }
}

bool Duration::operator==(const Duration &other) const {
    return (min == other.min) && (sec == other.sec);
}

bool Duration::operator!=(const Duration &other) const {
    return !(*this == other);
}

ostream& operator<<(ostream &os, const Duration &d) {
    os << d.min << ":" << setw(2) << setfill('0') << d.sec;
    return os;
}

istream& operator>>(istream &is, Duration &d) {
    char colon;
    int minutes, seconds;
    
    // Try to read in format "min:sec"
    if (is >> minutes >> colon >> seconds) {
        if (colon == ':') {
            d.min = minutes;
            d.sec = seconds;
            d.normalize();
            return is;
        }
    }
    
    // If format fails, clear error and try reading two integers
    is.clear();
    cout << "Enter minutes: ";
    is >> minutes;
    cout << "Enter seconds: ";
    is >> seconds;
    
    d.min = minutes;
    d.sec = seconds;
    d.normalize();
    
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
    is >> s.duration;
    return is;
}