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
int innerPadding=0;

void print_in_centre(string str)
{
    innerPadding = (boxWidth - 2 - static_cast<int>(str.length())) / 2;
    if (innerPadding < 0)
    {
        innerPadding = 0;
    }
    cout<<"\n";              
    cout << string(leftPadding, ' ') << string(innerPadding, ' ') << str;
}

void go_to_playlist_main_page()
{
    char p_window='P';
    string s="Press 'P' to go to Playlists-Operations Window: ";
    do 
    {
        print_in_centre(s);
        cin>>p_window;
    }while(p_window!='P');
}

class window3
{
    public:
        void create_playlist()
        {
            system("cls");

            string s1="Enter Name Of Playlist: ";
            string s2="Give brief description regarding the playlist: ";
            string playlist_name;
            string playlist_description;

            print_in_centre(s1);
            cin>>playlist_name;
            //getline(cin,playlist_name);

            print_in_centre(s2);
            cin>>playlist_description;
            //getline(cin,playlist_description);

            Playlist p1(playlist_name);
            MyPlaylists.push_back(p1);
            cout<<"\n\n";
            
            string s3="Playlist Succesfully Created! ";
            print_in_centre(s3);

            cout<<"\n";
            string s4="Total Playlists: ";
            print_in_centre(s4);
            cout << MyPlaylists.size();

            cout<<"\n\n";

            go_to_playlist_main_page();
            
            w3();
        }

        void add_song_to_playlist()
        {
            system("cls");

            display_all_playlists();
            cout<<"\n\n";
            string s1="Which Playlist do you want to add a song to?: ";
            int playlist_index;
            print_in_centre(s1);
            cin>>playlist_index;

            system("cls");

            //display_library();
            cout<<"\n\n";
            string s2="Which Song do you want to add to the playlist?: ";
            int song_index;
            print_in_centre(s2);
            cin>>song_index;

            int check=0;
            for(int i=0;i<(((MyPlaylists[playlist_index]).songs).size());i++)
            {
                if((library[song_index]).getTitle()==((MyPlaylists[playlist_index]).songs[i]).getTitle())
                {
                    check=1;
                    break;
                }
            }
            if(check==1)
            {
                cout<<"\n\n";
                string s3="Song Already exists in playlist!";
                print_in_centre(s3);
            }
            else
            {
                MyPlaylists[playlist_index].addSong(library[song_index]);
                system("cls");
                string s4="Song added to playlist!";
                print_in_centre(s4);
                cout<<"\n\n";
                MyPlaylists[playlist_index].displaySongs();
            }

            cout<<"\n\n";

            go_to_playlist_main_page();
            
            w3();
        }

        void remove_song_from_playlist()
        {
            system("cls");

            display_all_playlists();
            cout<<"\n\n";

            string s1="Which Playlist do you want to remove a song from?: ";
            int playlist_index;
            print_in_centre(s1);
            cin>>playlist_index;

            system("cls");

            MyPlaylists[playlist_index].displaySongs();
            cout<<"\n\n";

            string s2="Which Song do you want to remove from the playlist?: ";
            int song_index;
            print_in_centre(s2);
            cin>>song_index;

            system("cls");

            MyPlaylists[playlist_index].removeSong(library[song_index].getTitle());
            system("cls");
            string s3="Song removed from playlist!";
            print_in_centre(s3);
            cout<<"\n\n";

            MyPlaylists[playlist_index].displaySongs();

            cout<<"\n\n";

            go_to_playlist_main_page();
            
            w3();
        }

        void find_playlist()
        {
            system("cls");

            string s1="Enter name of playlist: ";
            string find_name;
            print_in_centre(s1);
            cin>>find_name;
            cout<<"\n";

            int find=0;
            for(int i=0;i<MyPlaylists.size();i++)
            {
                if(find_name==MyPlaylists[i].playlistName)
                {
                    find=1;
                    string s2="Playlist found at index = "+to_string(i);
                    print_in_centre(s2);
                    break;
                }
            }
            if(find==0)
            {
                string s3="Playlist not found";
                print_in_centre(s3);
            }
            cout<<"\n\n";

            display_all_playlists();

            cout<<"\n\n";

            char p_window='P';

            go_to_playlist_main_page();
            
            w3();

        }

        void display_all_playlists()
        {
            system("cls");

            string s1="==Displayling All Playlists==";
            print_in_centre(s1);

            cout<<"\n\n";

            for(int i=0;i<MyPlaylists.size();i++)
            {
                string s2=to_string(i)+". "+MyPlaylists[i].playlistName+", Total Songs = "+string((MyPlaylists[i].songs).size());
                print_in_centre(s2);
                cout<<"\n";
            }

        }

        void delete_playlist()
        {
            system("cls");

            display_all_playlists();
            cout<<"\n\n";

            string s1="Which playlist do you want to remove?: ";
            int rem_index;
            print_in_centre(s1);
            cin>>rem_index;

            MyPlaylists.erase(MyPlaylists.begin()+rem_index);
            cout<<"\n\n";

            system("cls");

            string s2="Playlist successfully removed!";
            print_in_centre(s2);
            cout<<"\n\n";

            display_all_playlists();
            
            cout<<"\n\n";

            go_to_playlist_main_page();

            w3();
        }

        void merge_playlists()
        {
            system("cls");

            display_all_playlists();
            cout<<"\n\n";

            string s1="which Playlists do you want to merge?: ";
            int m1,m2;
            print_in_centre(s1);
            cin>>m1>>m2;
            
            string s2="Enter Name Of merged Playlist: ";
            string s3="Give brief description regarding the merged playlist: ";
            string playlist_name;
            string playlist_description;

            print_in_centre(s2);
            cin>>playlist_name;
            //getline(cin,playlist_name);

            print_in_centre(s3);
            cin>>playlist_description;
            //getline(cin,playlist_description);

            Playlist merged_playlist(playlist_name);
            merged=MyPlaylists[m1]+MyPlaylists[m2];
            MyPlaylists.push_back(merged_playlist);

            system("cls");

            display_all_playlists();

            cout<<"\n\n";

            go_to_playlist_main_page();

            w3();
        }

        void w3()
        {
            system("cls");
            print_window3_ui();

            int choice;
            string s1="Enter desired choice: ";
            print_in_centre(s1);
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