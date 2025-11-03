#include<bits/stdc++.h>
#include<string>
#include <cstdlib> 
#include<vector>
#include "models\songClass.hpp"
#include "Core\playlist.hpp"
//#include "mainmenu.cpp"

vector<Playlist> MyPlaylists;

const int totalCols = 150;
const int boxWidth = 60;

int leftPadding = (totalCols - boxWidth) / 2;
int totalRows = 40;
int menuHeight = 11;
int topPadding = (totalRows - menuHeight) / 2;

class window3
{
    public:
        void create_playlist()
        {
            system("cls");
            // for (int i = 0; i < topPadding; i++)
            //     cout << endl;

            string s3="Enter Name Of Playlist: ";
            string s4="Give brief description regarding the playlist: ";
            string playlist_name;
            string playlist_description;

            int innerPadding = (boxWidth - 2 - static_cast<int>(s3.length())) / 2;
                if (innerPadding < 0)
                    innerPadding = 0;

                cout<<"\n";
                    cout << string(leftPadding, ' ')
                    << string(innerPadding, ' ') << s3;
                    cin>>playlist_name;
                    //getline(cin,playlist_name);

            innerPadding = (boxWidth - 2 - static_cast<int>(s4.length())) / 2;
                if (innerPadding < 0)
                    innerPadding = 0;

                cout << string(leftPadding, ' ')
                    << string(innerPadding, ' ') << s4;
                    cin>>playlist_description;
                    //getline(cin,playlist_description);

            Playlist p1(playlist_name);
            MyPlaylists.push_back(p1);
            cout<<"\n\n";
            
            string s5="Playlist Succesfully Created! ";
            innerPadding = (boxWidth - 2 - static_cast<int>(s5.length())) / 2;
                if (innerPadding < 0)
                    innerPadding = 0;

                cout << string(leftPadding, ' ')
                    << string(innerPadding, ' ') << s5;

            cout<<"\n";
            string s6="Total Playlists: ";
            innerPadding = (boxWidth - 2 - static_cast<int>(s6.length())) / 2;
                if (innerPadding < 0)
                    innerPadding = 0;

                cout << string(leftPadding, ' ')
                    << string(innerPadding, ' ') << s6 << MyPlaylists.size();

            cout<<"\n\n";
            char p_window='P';

            string s7="Press 'P' to go to Playlists-Operations Window: ";
            do 
            {
                innerPadding = (boxWidth - 2 - static_cast<int>(s7.length())) / 2;
                if (innerPadding < 0)
                    innerPadding = 0;

                cout << string(leftPadding, ' ')
                    << string(innerPadding, ' ') << s7;
                    cin>>p_window;
            }while(p_window!='P');
            
            w3();
        }

        void add_song_to_playlist()
        {
            system("cls");

            display_all_playlists();
            cout<<"\n\n";
            string s8="Which Playlist do you want to add a song to?: ";
            int playlist_index;
            int innerPadding = (boxWidth - 2 - static_cast<int>(s8.length())) / 2;
                if (innerPadding < 0)
                    innerPadding = 0;

                cout << string(leftPadding, ' ')
                    << string(innerPadding, ' ') << s8;
                    cin>>playlist_index;

            system("cls");

            //display_library();
            cout<<"\n\n";
            string s9="Which Song do you want to add a to the playlist?: ";
            int song_index;
            innerPadding = (boxWidth - 2 - static_cast<int>(s9.length())) / 2;
                if (innerPadding < 0)
                    innerPadding = 0;

                cout << string(leftPadding, ' ')
                    << string(innerPadding, ' ') << s9;
                    cin>>song_index;

            int check=0;
            for(int i=0;i<(((MyPlaylists[playlist_index]).songs).size());i++)
            {
                if((library[song_index]).getTitle()==(MyPlaylists[playlist_index]).songs[i])
                {
                    check=1;
                    break;
                }
            }
            if(check==1)
            {
                string s10="Song Already exists in playlist!";
                    innerPadding = (boxWidth - 2 - static_cast<int>(s10.length())) / 2;
                    if (innerPadding < 0)
                        innerPadding = 0;

                    cout << string(leftPadding, ' ')
                        << string(innerPadding, ' ') << s10;
                        system("cls");
            }
            else
            {
                MyPlaylists[playlist_index].addSong(library[song_index]);
                system("cls");
                string s11="Song added to playlist!";
                    innerPadding = (boxWidth - 2 - static_cast<int>(s11.length())) / 2;
                    if (innerPadding < 0)
                        innerPadding = 0;

                    cout << string(leftPadding, ' ')
                        << string(innerPadding, ' ') << s11;
                cout<<"\n\n";
                MyPlaylists[playlist_index].displaySongs();
            }

            cout<<"\n\n";
            char p_window='P';

            string s7="Press 'P' to go to Playlists-Operations Window: ";
            do 
            {
                innerPadding = (boxWidth - 2 - static_cast<int>(s7.length())) / 2;
                if (innerPadding < 0)
                    innerPadding = 0;

                cout << string(leftPadding, ' ')
                    << string(innerPadding, ' ') << s7;
                    cin>>p_window;
            }while(p_window!='P')
            
            w3();
        }

        void remove_song_from_playlist()
        {
            system("cls");

            display_all_playlists();
            cout<<"\n\n";
            string s8="Which Playlist do you want to remove a song from?: ";
            int playlist_index;
            int innerPadding = (boxWidth - 2 - static_cast<int>(s8.length())) / 2;
                if (innerPadding < 0)
                    innerPadding = 0;

                cout << string(leftPadding, ' ')
                    << string(innerPadding, ' ') << s8;
                    cin>>playlist_index;

            system("cls");

            MyPlaylists[playlist_index].displaySongs();
            cout<<"\n\n";
            string s9="Which Song do you want to remove from the playlist?: ";
            int song_index;
            innerPadding = (boxWidth - 2 - static_cast<int>(s9.length())) / 2;
                if (innerPadding < 0)
                    innerPadding = 0;

                cout << string(leftPadding, ' ')
                    << string(innerPadding, ' ') << s9;
                    cin>>song_index;

            system("cls");

            MyPlaylists[playlist_index].removeSong(library[song_index].getTitle());
                system("cls");
                string s11="Song removed from playlist!";
                    innerPadding = (boxWidth - 2 - static_cast<int>(s11.length())) / 2;
                    if (innerPadding < 0)
                        innerPadding = 0;

                    cout << string(leftPadding, ' ')
                        << string(innerPadding, ' ') << s11;
                cout<<"\n\n";
                MyPlaylists[playlist_index].displaySongs();

                cout<<"\n\n";
            char p_window='P';

            string s7="Press 'P' to go to Playlists-Operations Window: ";
            do 
            {
                innerPadding = (boxWidth - 2 - static_cast<int>(s7.length())) / 2;
                if (innerPadding < 0)
                    innerPadding = 0;

                cout << string(leftPadding, ' ')
                    << string(innerPadding, ' ') << s7;
                    cin>>p_window;
            }while(p_window!='P')
            
            w3();
        }

        void find_playlist()
        {
            system("cls");

            string s1="Enter name of playlist: ";
            string find_name;
                    int innerPadding = (boxWidth - 2 - static_cast<int>(s1.length())) / 2;
                    if (innerPadding < 0)
                        innerPadding = 0;

                    cout << string(leftPadding, ' ')
                        << string(innerPadding, ' ') << s1;
                        cin>>find_name;
                cout<<"\n";
            int find=0;
            for(int i=0;i<MyPlaylists[i].size();i++)
            {
                if(find_name==MyPlaylists[i].playlistName)
                {
                    find=1;
                    string s2="Playlist found at index = "+to_string(i);
                            innerPadding = (boxWidth - 2 - static_cast<int>(s2.length())) / 2;
                            if (innerPadding < 0)
                                innerPadding = 0;

                            cout << string(leftPadding, ' ')
                                << string(innerPadding, ' ') << s2;
                    break;
                }
            }
            if(find==0)
            {
                string s3="Playlist not found";
                            innerPadding = (boxWidth - 2 - static_cast<int>(s3.length())) / 2;
                            if (innerPadding < 0)
                                innerPadding = 0;

                            cout << string(leftPadding, ' ')
                                << string(innerPadding, ' ') << s3;
            }
            cout<<"\n\n";

            display_all_playlists();

            cout<<"\n\n";
            char p_window='P';

            string s7="Press 'P' to go to Playlists-Operations Window: ";
            do 
            {
                innerPadding = (boxWidth - 2 - static_cast<int>(s7.length())) / 2;
                if (innerPadding < 0)
                    innerPadding = 0;

                cout << string(leftPadding, ' ')
                    << string(innerPadding, ' ') << s7;
                    cin>>p_window;
            }while(p_window!='P')
            
            w3();

        }

        void display_all_playlists()
        {
            system("cls");

            string s1="==Displayling All Playlists==";
                    int innerPadding = (boxWidth - 2 - static_cast<int>(s1.length())) / 2;
                    if (innerPadding < 0)
                        innerPadding = 0;

                    cout << string(leftPadding, ' ')
                        << string(innerPadding, ' ') << s1;
                cout<<"\n\n";

            for(int i=0;i<MyPlaylists.size();i++)
            {
                string s2=to_string(i)+". "+MyPlaylists[i].playlistName+", Total Songs = "+string((MyPlaylists[i].songs).size());
                    innerPadding = (boxWidth - 2 - static_cast<int>(s2.length())) / 2;
                    if (innerPadding < 0)
                        innerPadding = 0;

                    cout << string(leftPadding, ' ')
                        << string(innerPadding, ' ') << s2;
                cout<<"\n";
            }

        }

        void delete_playlist()
        {
            system("cls");
            display_all_playlists();

            cout<<"\n";
            string s1="Which playlist do you want to remove?: ";
            int rem_index;
            int innerPadding = (boxWidth - 2 - static_cast<int>(s1.length())) / 2;
                    if (innerPadding < 0)
                        innerPadding = 0;

                    cout << string(leftPadding, ' ')
                        << string(innerPadding, ' ') << s1;
                        cin>>rem_index;

            MyPlaylists.erase(MyPlaylists.begin()+rem_index);
            cout<<"\n\n";
            system("cls");
            string s2="Playlist successfully removed!";
            innerPadding = (boxWidth - 2 - static_cast<int>(s1.length())) / 2;
                    if (innerPadding < 0)
                        innerPadding = 0;

                    cout << string(leftPadding, ' ')
                        << string(innerPadding, ' ') << s2;
            cout<<"\n\n";
            display_all_playlists();
            
            cout<<"\n\n";
            char p_window='P';

            string s7="Press 'P' to go to Playlists-Operations Window: ";
            do 
            {
                innerPadding = (boxWidth - 2 - static_cast<int>(s7.length())) / 2;
                if (innerPadding < 0)
                    innerPadding = 0;

                cout << string(leftPadding, ' ')
                    << string(innerPadding, ' ') << s7;
                    cin>>p_window;
            }while(p_window!='P');

            w3();
        }

        void merge_playlists()
        {
            system("cls");

            display_all_playlists();
            cout<<"\n\n";

            string s1="which Playlists do you want to merge?: ";
            int m1,m2;
            int innerPadding = (boxWidth - 2 - static_cast<int>(s1.length())) / 2;
                    if (innerPadding < 0)
                        innerPadding = 0;

                    cout << string(leftPadding, ' ')
                        << string(innerPadding, ' ') << s1;
                        cin>>m1>>m2;
            
            string s3="Enter Name Of merged Playlist: ";
            string s4="Give brief description regarding the merged playlist: ";
            string playlist_name;
            string playlist_description;

            innerPadding = (boxWidth - 2 - static_cast<int>(s3.length())) / 2;
                if (innerPadding < 0)
                    innerPadding = 0;

                cout<<"\n";
                    cout << string(leftPadding, ' ')
                    << string(innerPadding, ' ') << s3;
                    cin>>playlist_name;
                    //getline(cin,playlist_name);

            innerPadding = (boxWidth - 2 - static_cast<int>(s4.length())) / 2;
                if (innerPadding < 0)
                    innerPadding = 0;

                cout << string(leftPadding, ' ')
                    << string(innerPadding, ' ') << s4;
                    cin>>playlist_description;
                    //getline(cin,playlist_description);

            Playlist merged(playlist_name);
            merged=MyPlaylists[m1]+MyPlaylists[m2];
            MyPlaylists.push_back(merged);

            system("cls");

            display_all_playlists();

            cout<<"\n\n";
            char p_window='P';

            string s7="Press 'P' to go to Playlists-Operations Window: ";
            do 
            {
                innerPadding = (boxWidth - 2 - static_cast<int>(s7.length())) / 2;
                if (innerPadding < 0)
                    innerPadding = 0;

                cout << string(leftPadding, ' ')
                    << string(innerPadding, ' ') << s7;
                    cin>>p_window;
            }while(p_window!='P');

            w3();
        }

        void w3()
        {
            system("cls");
            print_window3_ui();
            int choice;
            string s2="Enter desired choice: ";

            int innerPadding = (boxWidth - 2 - static_cast<int>(s2.length())) / 2;
                if (innerPadding < 0)
                    innerPadding = 0;

                cout<<"\n";
                    cout << string(leftPadding, ' ')
                    << string(innerPadding, ' ') << s2;
                    cin>>choice;

            switch(choice)
            {
                case 1:
                {
                    create_playlist();
                    break;
                }
                case 2:
                {
                    add_song_to_playlist();
                    break;
                }
                case 3:
                {
                    remove_song_from_playlist();
                    break;
                }
                case 4:
                {
                    find_playlist();
                    break;
                }
                case 5:
                {
                    display_all_playlists();
                    break;
                }
                case 6:
                {
                    delete_playlist();
                    break;
                }
                case 7:
                {
                    merge_playlists();
                    break;
                }
                case 8:
                {
                    //mainmenu.cpp calling funtion
                    break;
                }
                default:
                {
                    cout<<"Invalid Choice!";
                    break;
                }
            }
        }

        void print_window3_ui()
        {
            for (int i = 0; i < topPadding; i++)
                cout << endl;

            cout << string(leftPadding, ' ') << " " << string(boxWidth - 2, '_') << " " << endl;

            string lines[] = 
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
    window3 test;
    test.w3();
    return 0;
}