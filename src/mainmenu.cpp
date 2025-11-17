#include <iostream>
#include <string>
#include <algorithm>
#include <cstdlib>
#include <limits>
#include <conio.h>
#include "playlist.hpp"
#include "library.hpp"
#include "mediaplayer.hpp"
#include "window3.hpp"
#include "models/songClass.hpp"
using namespace std;
class developerwindow
{
public:
    void devfunc(string ps, MusicLibrary &lib)
    {
        dev(ps);
        char ch2 = getch();
        int local;
        switch (ch2)
        {
        case '1':
        {
            system("cls");
            Song newSong(1);
            if (lib.addSong(newSong))
                cout << "Song added successfully!" << endl;
            else
                cout << "Failed to add song." << endl;
            break;
        }
        case '2':
            system("cls");
            local=lib.displayAllSongs();
            lib.removeSong(local);
            break;
        case '3':
            system("cls");
            cout << "Exiting Developer Mode...\n";
            break;
        default:
            cout << "\nINVALID CHOICE\n";
        }
    }

    void dev(string p)
    {
        string password = "aaa";
        system("cls");

        const int totalCols = 150;
        const int boxWidth = 60;
        int leftPadding = (totalCols - boxWidth) / 2;
        int totalRows = 40;
        int menuHeight = 8;
        int topPadding = (totalRows - menuHeight) / 2;

        for (int i = 0; i < topPadding; i++)
            cout << endl;

        if (p == password)
        {
            // Top border
            cout << string(leftPadding, ' ') << ' ' << string(boxWidth - 2, '_') << endl;

            string lines[] = {
                "Access Granted! Welcome, Developer.",
                "-------------------------------------",
                "1. Add a Song.",
                "2. Remove a Song.",
                "3. Exit Developer Mode"};

            // Box content
            for (const string &line : lines)
            {
                int innerPadding = (boxWidth - 2 - static_cast<int>(line.length())) / 2;
                if (innerPadding < 0)
                    innerPadding = 0;

                cout << string(leftPadding, ' ')
                     << "|" << string(innerPadding, ' ') << line
                     << string(boxWidth - 2 - innerPadding - line.length(), ' ') << "|" << endl;
            }

            // Bottom border
            cout << string(leftPadding, ' ') << "|" << string(boxWidth - 2, '_') << "|" << endl;

            // Centered choice prompt
            string choicePrompt = "Enter Choice: ";
            int innerPadding = (totalCols - static_cast<int>(choicePrompt.length())) / 2;
            cout << endl
                 << string(innerPadding, ' ') << choicePrompt;
        }
        else
        {
            string errorMsg = "Incorrect Password! Returning to Main Menu!";
            cout << endl
                 << string(leftPadding + (boxWidth - static_cast<int>(errorMsg.length())) / 2, ' ')
                 << errorMsg << endl;
        }
    }
};
class mainwindow
{
public:
    void window1()
    {
        MusicLibrary ob2;
        window3 ob3;
        vector<Song> temp = ob2.stringify();
        for (auto s : temp)
        {
            ob2.addSong(s);
        }
        while (true)
        {
            printMenuBox();
            char choice;
            choice = getch();
            string tt = "";
            Song s;
            interfacemusicplayer *ptr2;
            switch (choice)
            {
            case '1':
            {
               while(true)
               {
                     system("cls");
                int x = ob2.displayAllSongs();
                if(x==-1)
                {
                    break;
                }
                Song s = ob2.getAllSongs()[x];
                interfacemusicplayer *ptr2 = new interfacemusicplayer(s);
               }
                break;
            }

            case '2':
            {
                system("cls");
                cout << "Enter song title to search: ";
                cin >> ws;
                getline(cin, tt);

                Song *ptr = ob2.findSong(tt);

                if (ptr == nullptr)
                    cout << "Song not found\n";
                else
                {
                    cout << "Song found\n";
                    // ...
                }
                break;
            }

            case '3':
            {
                system("cls");
                ob3.w3();
                break;
            }

            case '4':
            {
                system("cls");
                int x = ob2.displayAllSongs();
                Song s = ob2.getAllSongs()[x];
                interfacemusicplayer *ptr2 = new interfacemusicplayer(s);
                break;
            }

            case '5':
            {
                system("cls");
                string pass;
                cout << "Enter Password: ";
                getline(cin, pass);
                developerwindow d;
                d.devfunc(pass, ob2);
                break;
            }

            case '6':
            {
                system("cls");
                cout << "Exiting and saving...\n";
                return;
            }

            default:
            {
                cout << "\nINVALID CHOICE\n";
            }
            }

            cout << "\nPress any key to return to the main menu...\n";
            system("pause");
            system("cls");
        }
    }

    void printMenuBox()
    {
        const int totalCols = 150;
        const int boxWidth = 60;

        int leftPadding = (totalCols - boxWidth) / 2;
        int totalRows = 40;
        int menuHeight = 11;
        int topPadding = (totalRows - menuHeight) / 2;

        for (int i = 0; i < topPadding; i++)
            cout << endl;

        cout << string(leftPadding, ' ') << " " << string(boxWidth - 2, '_') << " " << endl;

        string lines[] = {
            "===== MUSIC LIBRARY MAIN MENU =====",
            "1. View All Songs",
            "2. Search Song",
            "3. Playlists",
            "4. Play Song",
            "5. Developer Options",
            "6. Save & Exit",
            "Enter choice: "};

        for (const string &line : lines)
        {
            int innerPadding = (boxWidth - 2 - static_cast<int>(line.length())) / 2;
            if (innerPadding < 0)
                innerPadding = 0;

            cout << string(leftPadding, ' ')
                 << "|" << string(innerPadding, ' ') << line
                 << string(boxWidth - 2 - innerPadding - line.length(), ' ') << "|" << endl;
        }

        cout << string(leftPadding, ' ') << "|" << string(boxWidth - 2, '_') << "|" << endl;
    }
};

int main()
{
    mainwindow ob;
    ob.window1();
    return 0;
}