#include <bits/stdc++.h>
#include <string>
#include <cstdlib> 
#include <vector>
#include "models\songClass.hpp"
#include "Core\playlist.hpp"
#include<conio.h>
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
                  
    cout << string(leftPadding, ' ') << string(innerPadding, ' ') << str;
}



class window3
{
    public:
        void create_playlist()
        {
            system("cls");

            string s1="Enter Name Of Playlist: ";
            string playlist_name;
            print_in_centre(s1);
            cin>>playlist_name;
            //getline(cin,playlist_name);

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

       getch();
            
            
        }
        /*
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
            for(int i=0;i<(((MyPlaylists[playlist_index]).want_playlist_songs()).size());i++)
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

          
           
        }*/

        /*void remove_song_from_playlist(int index)
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

            
        }*/

       /* void find_playlist()
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
                if(find_name==MyPlaylists[i].PLname)
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

        
            
           

        }
        */
        void display_all_playlists()
        {
            system("cls");
            /*
            string s1="==Displayling All Playlists==";
            print_in_centre(s1);

            cout<<"\n\n";

            for(int i=0;i<MyPlaylists.size();i++)
            {
                string s2="  "+MyPlaylists[i].PLname()+", Total Songs = "+to_string((MyPlaylists[i].want_playlist_songs()).size());
                print_in_centre(s2);
                cout<<"\n";
            }*/
            if(MyPlaylists.size()==0)
            {
                string s10="There are no playlists!";
                print_in_centre(s10);
                getch();
                return;
            }
            int i=0;
            while(true)
            {
                for(int i=0;i<15;i++)
            {
                cout<<endl;
            }
                int counter=0;
                for(auto& a:MyPlaylists)
                {
                    string s2="  "+a.PLname()+", Total Songs = "+to_string((a.want_playlist_songs()).size());
                    if(counter==i)
                    {
                        cout<<"->"<<s2;
                    }
                    else
                    cout<<"  "<<s2;
                    counter++;
                    cout<<endl;
                }
                char c;
                c=getch();
                if(c=='w')
                {
                    if(i==0)
                    {
                        ;
                    }
                    else{
                        i--;
                    }
                }
                else if(c=='s')
                {
                        if(i==MyPlaylists.size()-1)
                        {
                            i=0;
                        }
                        else{
                            i++;
                        }
                }
                else if(c=='e'||c=='E')
                        break;
                system("cls");
            }
            getch();

        }

       /* void delete_playlist()
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

            Playlist merged_playlist(playlist_name,playlist_description);
            merged_playlist=MyPlaylists[m1]+MyPlaylists[m2];
            MyPlaylists.push_back(merged_playlist);

            system("cls");
            string s4="Merged Playlist successfully created!";
            print_in_centre(s4);
            cout<<"\n\n"
            display_all_playlists();

            cout<<"\n\n";

            
        }
                */
        void w3()
        {
            system("cls");
           while(true)
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
                    //add_song_to_playlist();
                    break;
                }
                case 3:
                {
                   // remove_song_from_playlist();
                    break;
                }
                case 4:
                {
                    // find_playlist();
                    break;
                }
                case 5:
                {
                    display_all_playlists();
                    break;
                }
                case 6:
                {
                   // delete_playlist();
                    break;
                }
                case 7:
                {
                    //merge_playlists();
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
             cout<<"enter E/e to exit";
             char c;
             cin>>c;
             if(c=='E'||c=='e')
             {
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