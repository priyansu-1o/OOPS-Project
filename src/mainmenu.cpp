#include <iostream>
#include <string>
#include <algorithm>
#include <cstdlib>
using namespace std;
class developerwindow
{
public:
    void dev(string p)
    {
        string password = "Arpit Randi";
        system("cls");
        if (p == password)
        {
            cout << "\nAccess Granted! Welcome, Developer.\n";
            cout << "-------------------------------------\n";
            cout << "1. yyy\n";
            cout << "2. xxx\n";
            cout << "3. Exit Developer Mode\n";
        }
        else
            cout << "\nIcorrect Password! TMKC Bhak!!\n";
    }
};
class mainwindow
{
public:
    void window1()
    {
        while (true)
        {
            printMenuBox();
            int choice;
            cin >> choice;
            cout << "\nYou entered: " << choice << endl;

            switch (choice)
            {
            case 1:
                system("cls");
                cout << "View All Songs feature coming soon...\n";
                break;
            case 2:
                system("cls");
                cout << "Search Song feature coming soon...\n";
                break;
            case 3:
                system("cls");
                cout << "Playlists feature coming soon...\n";
                break;
            case 4:
                system("cls");
                cout << "Play Song feature coming soon...\n";
                break;
            case 5:
            {
                system("cls");
                string pass;
                cout << "==============================\n";
                cout << "   Developer Access Required\n";
                cout << "==============================\n\n";
                cout << "Enter Password: ";
                cin.ignore();
                getline(cin, pass);
                developerwindow d;
                d.dev(pass);
                break;
            }
            case 6:
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