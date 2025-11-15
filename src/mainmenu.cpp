#include <iostream>
#include <string>
#include <algorithm>
#include <cstdlib>
#include <limits>
#include <conio.h>
#include "Core/library.hpp"
#include "models/songClass.hpp"
using namespace std;
class developerwindow
{
public:
    void devfunc(string ps, MusicLibrary &lib)
    {
        dev(ps);
        char ch2 = getch();
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
            cout << "xxx feature coming soon...\n";
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
                "2. xxx",
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
            string errorMsg = "Incorrect Password! TMKC Bhak!!";
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
        while (true)
        {
            printMenuBox();
            char choice;
            choice = getch();

            switch (choice)
            {
            case '1':
                system("cls");
                ob2.displayAllSongs();
                break;
            case '2':
                system("cls");
                cout << "Search Song feature coming soon...\n";
                break;
            case '3':
                system("cls");
                cout << "Playlists feature coming soon...\n";
                break;
            case '4':
                system("cls");
                cout << "Play Song feature coming soon...\n";
                break;
            case '5':
            {
                system("cls");
                string pass;
                cout << "==============================\n";
                cout << "   Developer Access Required\n";
                cout << "==============================\n\n";
                cout << "Enter Password: ";
                cin >> ws; // flush whitespace
                getline(cin, pass);
                developerwindow d;
                d.devfunc(pass, ob2);
                break;
            }
            case '6':
                system("cls");
                cout << "Exiting and saving...\n";
                return;
            default:
                cout << "\nINVALID CHOICE\n";
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