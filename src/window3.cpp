#include <bits/stdc++.h>
#include <string>
#include<windows.h>
#include <cstdlib> 
#include <vector>
#include "models\songClass.hpp"
#include "playlist.hpp"
#include "library.hpp"
#include "mediaplayer.hpp"
#include<conio.h>
#include "window3.hpp"

 int totalCols = 150;
 int boxWidth = 60;

int leftPadding = (totalCols - boxWidth) / 2;
int totalRows = 40;
int menuHeight = 11;
int topPadding = (totalRows - menuHeight) / 2;
int innerPadding = 0;

void print_in_centre(std::string str)
{
    innerPadding = (boxWidth - 2 - static_cast<int>(str.length())) / 2;
    if (innerPadding < 0)
    {
        innerPadding = 0;
    }
    std::cout << std::string(leftPadding, ' ') << std::string(innerPadding, ' ') << str;
}

void window3::create_playlist(MusicLibrary& lib)
{
    system("cls");
    std::cout << "\n\n";
    std::string s1 = "Enter Name Of Playlist: ";
    std::string playlist_name;
    print_in_centre(s1);
    getline(std::cin >> std::ws, playlist_name);

    Playlist p1(playlist_name);
    lib.playlists.push_back(p1);
    std::cout << "\n\n";

    std::string s3 = "Playlist Succesfully Created! ";
    print_in_centre(s3);

    std::cout << "\n";
    std::string s4 = "Total Playlists: ";
    print_in_centre(s4);
    std::cout << lib.playlists.size();

    std::cout << "\n\n\n";

    char open_playlist;
    std::string yahoo = "Press [O] to open the newly created playlist: ";
    print_in_centre(yahoo);
    open_playlist = getch();

    if (open_playlist == 'o' || open_playlist == 'O')
    {
        manage_single_playlist(lib.playlists.size() - 1,lib);
    }
    else
    {
        std::cout << "\n\n\n";
        std::string s4 = "-- press any key to continue --";
        print_in_centre(s4);
        getch();
    }
}

void window3::manage_single_playlist(int playlist_index, MusicLibrary& lib)
{
    while (true)
    {
        system("cls");
        std::cout << "\n\n";
        std::string title = "Managing Playlist: " + lib.playlists[playlist_index].PLname();
        print_in_centre(title);
        std::cout << "\n\n\n";

        std::string lines[] = {
            "===== PLAYLIST OPERATIONS =====",
            " ",
            "1. Add Song to Playlist",
            "2. Remove Song from Playlist",
            "3. Display All Songs",
            "4. Play a Song",
            "5. Get Total Duration",
            "6. Back to Main Menu"};

        for (const std::string &line : lines)
        {
            int innerPadding = (boxWidth - 2 - static_cast<int>(line.length())) / 2;
            if (innerPadding < 0)
                innerPadding = 0;

            std::cout << std::string(leftPadding, ' ')
                      << "|" << std::string(innerPadding, ' ') << line
                      << std::string(boxWidth - 2 - innerPadding - line.length(), ' ') << "|" << std::endl;
        }

        std::cout << "\n\n";
        char choice;
        std::string s1 = "Enter desired choice: ";
        print_in_centre(s1);
        choice = getch();

        switch (choice)
        {
        case '1':
            add_song_to_specific_playlist(playlist_index, lib);
            break;
        case '2':
            remove_song_from_specific_playlist(playlist_index, lib);
            break;
        case '3':
            system("cls");
            lib.playlists[playlist_index].displaySongs();
            std::cout << "\n\nPress any key to continue...";
            getch();
            break;
        case '4':
            play_song_from_specific_playlist(playlist_index, lib);
            break;
        case '5':
            system("cls");
            std::cout << "\n\nTotal Duration: " << lib.playlists[playlist_index].totalduration() << " seconds\n\n";
            std::cout << "Press any key to continue...";
            getch();
            break;
        case '6':
            return;
        default:
            std::cout << "Invalid Choice!";
            getch();
            break;
        }
    }
}

void window3::add_song_to_specific_playlist(int playlist_index,  MusicLibrary& lib)
{
    system("cls");
    std::cout << "\n\n";
    std::string title = "Adding Song to: " + lib.playlists[playlist_index].PLname();
    print_in_centre(title);
    std::cout << "\n\n";

    string add = "Select The song you want to add to the playlist: ";
    print_in_centre(add);
    cout<<"\n\n";
    int k = lib.displayAllSongs();
    if(k==-1)
    return;
    Song new_song = lib.getAllSongs()[k]; 

    int check = 0;
    for (const auto &s : lib.playlists[playlist_index].want_playlist_songs())
    {
        if (new_song.getTitle() == s.getTitle())
        {
            check = 1;
            break;
        }
    }
    if (check == 1)
    {
        std::cout << "\n\n";
        std::string s3 = "Song Already exists in playlist!";
        print_in_centre(s3);
    }
    else
    {
        lib.playlists[playlist_index].addSong(new_song);
        std::cout << "\n\n";
        std::string s4 = "Song added to playlist successfully!";
        print_in_centre(s4);
    }
    std::cout << "\n\nPress any key to continue...";
    getch();
}

void window3::remove_song_from_specific_playlist(int playlist_index,  MusicLibrary& lib)
{
    system("cls");
    if (lib.playlists[playlist_index].want_playlist_songs().empty())
    {
        print_in_centre("No songs in this playlist!");
        std::cout << "\n\nPress any key to continue...";
        getch();
        return;
    }

    std::cout << "\n\n";
    std::string title = "Removing Song from: " + lib.playlists[playlist_index].PLname();
    print_in_centre(title);
    std::cout << "\n\n";

    while (true)
    {
        int dltindex = lib.playlists[playlist_index].displaySongs();
        if (dltindex == -1)
        {
            break;
        }
        lib.playlists[playlist_index].removeSong(dltindex);
    }
}

void window3::play_song_from_specific_playlist(int playlist_index,MusicLibrary& lib)
{
    system("cls");
    int i = lib.playlists[playlist_index].displaySongs();
    if(i==-1)
        return;
    std::vector<Song> v = lib.playlists[playlist_index].want_playlist_songs();
    Song s = v[i];
    interfacemusicplayer p(s);
}

void window3::just_display_playlists(MusicLibrary& lib)
{
    if  (lib.playlists.size() == 0)
    {
        std::string str = "There are no playlists!";
        print_in_centre(str);
    }
    else
    {
        std::string s1 = "== Displayling All Playlists ==";
        print_in_centre(s1);
        std::cout << "\n\n";

        for (int i = 0; i < lib.playlists.size(); i++)
        {
            std::string s2 = std::to_string(i + 1) + ". " + lib.playlists[i].PLname() + ", Total Songs = " + std::to_string( lib.playlists[i].want_playlist_songs().size());
            print_in_centre(s2);
            std::cout << "\n";
        }
    }
}

void window3::add_song_to_playlist( MusicLibrary& lib)
{
    system("cls");

    std::string s1 = "Select the playlist you want to add a song to: ";
    int playlist_index;
    print_in_centre(s1);
    std::cout << "\n\n";

    playlist_index = ret_dis_play_index(lib);

    add_song_to_specific_playlist(playlist_index, lib);
}

void window3::remove_song_from_playlist(MusicLibrary& lib)
{
    system("cls");
       std::string s1 = "Select the playlist you want to remove a song from: ";
    int playlist_index;
    print_in_centre(s1);
    std::cout << "\n\n";

    while (true)
    {
      
        playlist_index = ret_dis_play_index(lib);
        if(playlist_index==-1)
            return;
        remove_song_from_specific_playlist(playlist_index,lib);
    }
}

void window3::find_playlist( MusicLibrary& lib)
{
    system("cls");

    std::string s1 = "Enter name of playlist to be searched for: ";
    std::string find_name;
    print_in_centre(s1);
    getline(std::cin >> std::ws, find_name);
    std::cout << "\n\n";

    int index = 0, find = 0;
    if  (lib.playlists.size() == 0)
    {
        std::string s10 = "There are no playlists!";
        print_in_centre(s10);
    }
    else
    {
        for (int i = 0; i < lib.playlists.size(); i++)
        {
            if (find_name == lib.playlists[i].PLname())
            {
                find = 1, index = i;
                break;
            }
        }

        if (find == 0)
        {
            std::string s3 = "--Playlist not found!--";
            print_in_centre(s3);

            std::cout << "\n\n\n";
            just_display_playlists(lib);

            std::cout << "\n\n\n";
            std::string s4 = "-- press any key to continue --";
            print_in_centre(s4);
            getch();
        }
        else
        {
            std::string s3 = "Playlist found at position = " + std::to_string(index + 1);
            print_in_centre(s3);

            std::cout << "\n\n\n";
            just_display_playlists(lib);

            std::cout << "\n\n\n";

            char open_playlist;
            std::string yahoo = "Press [O] to open the playlist/Press any key to go back ";
            print_in_centre(yahoo);
            open_playlist = getch();

            if (open_playlist == 'o' || open_playlist == 'O')
            {
                manage_single_playlist(index,lib);
            }
            else
            {
                return;
            }
        }
    }
}

void window3::display_all_playlists( MusicLibrary& lib)
{
    system("cls");

    if  (lib.playlists.size() == 0)
    {
        std::string s10 = "There are no playlists!";
        print_in_centre(s10);
        getch();
        return;
    }
    int i = 0;
    while (true)
    {
        std::vector<std::string> lines = {
            "Press [O] to open a playlist",
            "Press [D] to delete a playlist",
            "Press [E] to save and exit"};

        size_t maxWidth = 0;
        for (const std::string &s : lines)
        {
            if (s.length() > maxWidth)
            {
                maxWidth = s.length();
            }
        }

        const int padding = 2;
        const int innerWidth = maxWidth + 2 * padding;

        std::string horizontalBorder = "+";
        horizontalBorder.append(innerWidth, '-');
        horizontalBorder += "+";

        std::cout << horizontalBorder << "\n";

        for (const std::string &line : lines)
        {
            size_t lineLength = line.length();
            size_t totalPadding = innerWidth - lineLength;
            size_t leftPadding = totalPadding / 2;
            size_t rightPadding = totalPadding - leftPadding;

            std::cout << "|";
            std::cout << std::string(leftPadding, ' ');
            std::cout << line;
            std::cout << std::string(rightPadding, ' ');
            std::cout << "|\n";
        }

        std::cout << horizontalBorder << "\n";

        std::string s1 = "== Displayling All Playlists ==";
        print_in_centre(s1);
        std::cout << "\n\n";

        int counter = 0;
        for (auto &a : lib.playlists)
        {
            std::string s2 = "  " + a.PLname() + ", Total Songs = " + std::to_string((a.want_playlist_songs()).size());
            if (counter == i)
            {
                std::cout << "       ->" << s2;
            }
            else
            {
                std::cout << "         " << s2;
            }
            counter++;
            std::cout << std::endl;
        }
        char c;
        c = getch();
        if (c == 'w')
        {
            if (i == 0)
            {
                ;
            }
            else
            {
                i--;
            }
        }
        else if (c == 's')
        {
            if (i == lib.playlists.size() - 1)
            {
                i = 0;
            }
            else
            {
                i++;
            }
        }
        else if (c == 'o' || c == 'O')
        {
            manage_single_playlist(i,lib);
        }
        else if (c == 'd' || c == 'D')
        {
            if( i == lib.playlists.size() - 1)
            {
                i=0;
            }
            delete_by_index(i,lib);
           
        }
        else if (c == 'e' || c == 'E')
            break;
        system("cls");
    }
    std::cout << "\n\n";
    std::string strin = "press any key to continue: ";
    print_in_centre(strin);
    getch();
}
int window3::ret_dis_play_index(MusicLibrary& lib)
{
    std::cout << "\n\n";

    if (lib.playlists.size() == 0)
    {
        return -1;
    }

    int i = 0;
    while (true)
    {
        system("cls");
        std::cout << "+------------------------------------------------------+\n";
        std::cout << "|                Select Playlist                       |\n";
        std::cout << "+------------------------------------------------------+\n";

        int counter = 0;
        for (auto &a : lib.playlists)
        {
            std::string s2 = "  " + a.PLname() + ", Total Songs = " + std::to_string((a.want_playlist_songs()).size());
            if (counter == i)
            {
                std::cout << "|  --> " << s2;
            }
            else
            {
                std::cout << "|      " << s2;
            }
            // Fill the rest of the line with spaces
            int spaces = 58 - s2.length();
            for (int j = 0; j < spaces; ++j) std::cout << " ";
            std::cout << "|\n";
            counter++;
        }

        std::cout << "+------------------------------------------------------+\n";
        std::cout << "| Use 'w'/'s' to move, Enter to select, 'e' to exit    |\n";
        std::cout << "+------------------------------------------------------+\n";

        char c = getch();
        if (c == 'w')
        {
            if (i == 0)
            {
                // Do nothing
            }
            else
            {
                i--;
            }
        }
        else if (c == 's')
        {
            if (i == lib.playlists.size() - 1)
            {
                i = 0;
            }
            else
            {
                i++;
            }
        }
        else if (c == 13)
        {
            return i;
        }
        else if (c == 'e' || c == 'E')
        {
            break;
        }
    }
    return -1;
}

void window3::delete_by_index(int index,MusicLibrary& lib)
{
    lib.playlists.erase(lib.playlists.begin() + index);
    std::cout << "\n\n";
    std::string s2 = "Playlist successfully removed!";
    print_in_centre(s2);
}

void window3::delete_playlist(MusicLibrary& lib)
{
    system("cls");

    if  (lib.playlists.size() == 0)
    {
        std::string str = "There are no playlists!";
        print_in_centre(str);
        std::cout << "\n\n";
    }
    else
    {
        std::string s1 = "Select the playlist which you want to remove: ";
        print_in_centre(s1);
        std::cout << "\n\n";

        int rem_index = ret_dis_play_index(lib);

        lib.playlists.erase(lib.playlists.begin() + rem_index);
        std::cout << "\n\n";

        std::string s2 = "Playlist successfully removed!";
        print_in_centre(s2);
        std::cout << "\n\n";
    }

    std::string s3 = "-- Press any key to continue --";
    print_in_centre(s3);
    getch();
}

void window3::merge_playlists(MusicLibrary& lib)
{
    system("cls");

    std::string s1 = "Select 1st playlist to be merged: ";
    int m1, m2;
    print_in_centre(s1);
    std::cout << "\n\n";
    m1 = ret_dis_play_index(lib);

    system("cls");

    std::string s2 = "Select 2nd playlist to be merged: ";
    print_in_centre(s2);
    std::cout << "\n\n";
    m2 = ret_dis_play_index(lib);
    std::cout << "\n\n\n";

    std::string s3 = "Enter Name Of merged Playlist: ";
    std::string playlist_name;
    print_in_centre(s3);
    getline(std::cin >> std::ws, playlist_name);

    Playlist merged_playlist(playlist_name);
    merged_playlist = lib.playlists[m1] + lib.playlists[m2];
    merged_playlist.changename(playlist_name);
    lib.playlists.push_back(merged_playlist);

    std::cout << "\n";
    std::string s4 = "--Merged Playlist successfully created!--";
    print_in_centre(s4);
    std::cout << "\n\n\n";

    std::string s5 = "press any key to continue: ";
    print_in_centre(s5);
    getch();
}

void window3::w3( MusicLibrary& lib)
{
    system("cls");
    while (true)
    {
        system("cls");
        print_window3_ui();
        std::cout << "\n\n";
        char choice;
        std::string s1 = "Enter desired choice: ";
        print_in_centre(s1);
        choice = getch();

        switch (choice)
        {
        case '1':
        {
            create_playlist(lib);
            break;
        }
        case '2':
        {
            add_song_to_playlist(lib);
            break;
        }
        case '3':
        {
            remove_song_from_playlist(lib);
            break;
        }
        case '4':
        {
            find_playlist(lib);
            break;
        }
        case '5':
        {
            display_all_playlists(lib);
            break;
        }
        case '6':
        {
            delete_playlist(lib);
            break;
        }
        case '7':
        {
            merge_playlists(lib);
            break;
        }
        case '8':
        {
            break;
        }
        default:
        {
            std::cout << "Invalid Choice!";
            break;
        }
        }

        std::cout << "\n\n";

        std::string stri = "---   Exit [E] || Playlists Window [Any other key]   --- ";
        char c;
        print_in_centre(stri);

        c = getch();
        if (c == 'E' || c == 'e')
        {
            break;
        }
    }
}

void window3::print_window3_ui()
{
    for (int i = 0; i < topPadding; i++)
    {
        std::cout << std::endl;
    }

    std::cout << std::string(leftPadding, ' ') << " " << std::string(boxWidth - 2, '_') << " " << std::endl;

    std::string lines[] =
    {
            "===== PLAYLISTS =====",
            " ",
            "1. Create A Playlist",
            "2. Add Song To A Playlist",
            "3. Remove Song From A playlist",
            "4. Find Playlist",
            "5. Display All Playlists",
            "6. Delete Playlist",
            "7. Merge Playlists",
            "8. Go Back To Main Menu",
    };

    for (const std::string &line : lines)
    {
        int innerPadding = (boxWidth - 2 - static_cast<int>(line.length())) / 2;

        if (innerPadding < 0)
            innerPadding = 0;

        std::cout << std::string(leftPadding, ' ')
                  << "|" << std::string(innerPadding, ' ') << line
                  << std::string(boxWidth - 2 - innerPadding - line.length(), ' ') << "|" << std::endl;
    }

    std::cout << std::string(leftPadding, ' ') << "|" << std::string(boxWidth - 2, '_') << "|" << std::endl;
}

// int main()
// {
//     window3 test;
//     MusicLibrary l;
//     test.w3(l);

//     return 0;
// }