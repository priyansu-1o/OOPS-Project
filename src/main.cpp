#include "Core/playlist.hpp"
#include  "models/songClass.hpp"
#include "Core/library.hpp"
#include <conio.h>
#include <iostream>
#include <vector>
#include <sstream>
using namespace std;

int main() {
    MusicLibrary a;
    char ch;
    a.displayAllSongs();
    getch();
}

