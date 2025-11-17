#ifndef WINDOW3_HPP
#define WINDOW3_HPP

#include <bits/stdc++.h>
#include <string>
#include <cstdlib>
#include <vector>
#include "models/songClass.hpp"
#include "playlist.hpp"
#include "library.hpp"
#include "mediaplayer.hpp"
#include <conio.h>

extern std::vector<Playlist> MyPlaylists;
extern const int totalCols;
extern const int boxWidth;
extern int leftPadding;
extern int totalRows;
extern int menuHeight;
extern int topPadding;
extern int innerPadding;

void print_in_centre(std::string str);

class window3
{
private:

public:
    void create_playlist();
    void manage_single_playlist(int playlist_index);
    void add_song_to_specific_playlist(int playlist_index);
    void remove_song_from_specific_playlist(int playlist_index);
    void play_song_from_specific_playlist(int playlist_index);
    void just_display_playlists();
    void add_song_to_playlist();
    void remove_song_from_playlist();
    void find_playlist();
    void display_all_playlists();
    int ret_dis_play_index();
    void delete_by_index(int index);
    void delete_playlist();
    void merge_playlists();
    void w3();
    void print_window3_ui();
};

#endif