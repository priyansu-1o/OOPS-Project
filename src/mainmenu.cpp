
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
class mainwindow
{
public:
    void window1()
    {
        printMenuBox();
        int choice;
        cin >> choice;
        cout << "\nYou entered: " << choice << endl;

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
            "3. Create Playlist",
            "4. Add Song to Playlist",
            "5. Show Playlist Songs",
            "6. Play Song",
            "7. Save & Exit",
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