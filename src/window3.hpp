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
extern  int totalCols;
extern  int boxWidth;
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
    void create_playlist( MusicLibrary& lib);
    void manage_single_playlist(int playlist_index,  MusicLibrary& lib);
    void add_song_to_specific_playlist(int playlist_index,  MusicLibrary& lib);
    void remove_song_from_specific_playlist(int playlist_index,  MusicLibrary& lib);
    void play_song_from_specific_playlist(int playlist_index,  MusicLibrary& lib);
    void play_playlist(int playlist_index,MusicLibrary& lib);
    void just_display_playlists( MusicLibrary& lib);
    void add_song_to_playlist( MusicLibrary& lib);
    void remove_song_from_playlist( MusicLibrary& lib);
    void find_playlist( MusicLibrary& lib);
    void display_all_playlists( MusicLibrary& lib);
    int ret_dis_play_index( MusicLibrary& lib);
    void delete_by_index(int index,  MusicLibrary& lib);
    void delete_playlist( MusicLibrary& lib);
    void merge_playlists( MusicLibrary& lib);
    void w3( MusicLibrary& lib);
    void print_window3_ui();
};

#endif