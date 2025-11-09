#include <bits/stdc++.h>
#include <string>
#include <cstdlib> 
#include <vector>
#include "models\songClass.hpp"
#include "Core\playlist.hpp"
#include "Core\library.hpp"
#include "mediaplayer.hpp"
#include<conio.h>

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
    private:
           // vector<Playlist> MyPlaylists*  ;
    public:
        void create_playlist()
        {
            system("cls");

            string s1="Enter Name Of Playlist: ";
            string playlist_name;
            print_in_centre(s1);
            getline(cin>>ws,playlist_name);

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
            
            // Show playlist management menu for the newly created playlist
            manage_single_playlist(MyPlaylists.size() - 1);
        }

        void manage_single_playlist(int playlist_index)
        {
            while(true)
            {
                system("cls");
                cout<<"\n\n";
                string title = "Managing Playlist: " + MyPlaylists[playlist_index].PLname();
                print_in_centre(title);
                cout<<"\n\n";
                
               
                // Show menu options
                string lines[] = {
                    "===== PLAYLIST OPERATIONS =====",
                    " ",
                    "1. Add Song to Playlist",
                    "2. Remove Song from Playlist", 
                    "3. Display All Songs",
                    "4. Play a Song",
                    "5. Get Total Duration",
                    "6. Back to Main Menu"
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
                
                cout<<"\n\n";
                int choice;
                string s1="Enter desired choice: ";
                print_in_centre(s1);
                cin>>choice;
                cin.ignore();
                
                switch(choice)
                {
                    case 1:
                        add_song_to_specific_playlist(playlist_index);
                        break;
                    case 2:
                        remove_song_from_specific_playlist(playlist_index);
                        break;
                    case 3:
                        system("cls");
                        MyPlaylists[playlist_index].displaySongs();
                        cout<<"\n\nPress any key to continue...";
                        getch();
                        break;
                    case 4:
                        play_song_from_specific_playlist(playlist_index);
                        break;
                    case 5:
                        system("cls");
                        cout<<"\n\nTotal Duration: " << MyPlaylists[playlist_index].totalduration() << " seconds\n\n";
                        cout<<"Press any key to continue...";
                        getch();
                        break;
                    case 6:
                        return;
                    default:
                        cout<<"Invalid Choice!";
                        getch();
                        break;
                }
            }
        }

        void add_song_to_specific_playlist(int playlist_index)
        {
            system("cls");
            cout<<"\n\n";
            string title = "Adding Song to: " + MyPlaylists[playlist_index].PLname();
            print_in_centre(title);
            cout<<"\n\n";
            
            // Create a new Song - this will automatically ask for input via setInfo()
            Song newSong;
            
            // Check for duplicate
            int check=0;
            for(const auto& s : MyPlaylists[playlist_index].want_playlist_songs()) {
                if(newSong.getTitle() == s.getTitle()) {
                    check=1;
                    break;
                }
            }
            if(check==1) {
                cout<<"\n\n";
                string s3="Song Already exists in playlist!";
                print_in_centre(s3);
            } else {
                MyPlaylists[playlist_index].addSong(newSong);
                cout<<"\n\n";
                string s4="Song added to playlist successfully!";
                print_in_centre(s4);
            }
            cout<<"\n\nPress any key to continue...";
            getch();
        }

        void remove_song_from_specific_playlist(int playlist_index)
        {
            system("cls");
            if(MyPlaylists[playlist_index].want_playlist_songs().empty()) {
                print_in_centre("No songs in this playlist!");
                cout<<"\n\nPress any key to continue...";
                getch();
                return;
            }
            
            cout<<"\n\n";
            string title = "Removing Song from: " + MyPlaylists[playlist_index].PLname();
            print_in_centre(title);
            cout<<"\n\n";
            
            int dltindex=MyPlaylists[playlist_index].displaySongs();
            MyPlaylists[playlist_index].removeSong(dltindex);
            cout<<"\n\nPress any key to continue...";
            getch();
        }

        void play_song_from_specific_playlist(int playlist_index)
        {
            system("cls");
            int i=MyPlaylists[playlist_index].displaySongs();
            vector<Song> v=MyPlaylists[playlist_index].want_playlist_songs();
            Song s=v[i];
            interfacemusicplayer p(s);
            
        }
        
        void just_display_playlists()
        {
            if(MyPlaylists.size()==0)
            {
                string str="There are no playlists!";
                print_in_centre(str);
            }
            else
            {
                string s1="==Displayling All Playlists==";
                print_in_centre(s1);
                cout<<"\n\n";
                
                for(int i=0;i<MyPlaylists.size();i++)
                {
                    string s2=to_string(i)+". "+MyPlaylists[i].PLname()+", Total Songs = "+to_string((MyPlaylists[i].want_playlist_songs()).size());
                    print_in_centre(s2);
                    cout<<"\n";
                }
            }
        }

        /*void add_song_to_playlist()
        {
            system("cls");

            string s1="Select the playlist you want to add a song to: ";
            int playlist_index;
            print_in_centre(s1);
            cout<<"\n\n";

            playlist_index=ret_dis_play_index();

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
                if( (ml.getAllSongs()[song_index]).getTitle() == ( (MyPlaylists[playlist_index]).want_playlist_songs()[i] ).getTitle() )
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
                cout<<"\n\n";
                string s4="Song added to playlist!";
                print_in_centre(s4);
                //MyPlaylists[playlist_index].displaySongs();
            }
            cout<<"\n\n";

            string s5="press any key to continue: ";
            print_in_centre(s5);
            getch();
        }*/

        /*void remove_song_from_playlist(int index)
        {
            system("cls");

            display_all_playlists();
            cout<<"\n\n";

            string s1="Select the playlist you want to remove a song from: ";
            int playlist_index;
            print_in_centre(s1);
            
            playlist_index=ret_dis_play_index();

            system("cls");

            //MyPlaylists[playlist_index].displaySongs();
            cout<<"\n\n";

            string s2="Which Song do you want to remove from the playlist?: ";
            int song_index;
            print_in_centre(s2);
            cin>>song_index;

            cout<<"\n\n";

            MyPlaylists[playlist_index].removeSong(library[song_index].getTitle());
            string s3="Song removed from playlist!";
            print_in_centre(s3);
            cout<<"\n\n";

            string s4="press any key to continue: ";
            print_in_centre(s4);
            getch();
        }*/
        
        void find_playlist()
        {
            system("cls");

            string s1="Enter name of playlist to be searched for: ";
            string find_name;
            print_in_centre(s1);
            getline(cin>>ws,find_name);
            cout<<"\n\n";

            if(MyPlaylists.size()==0)
            {
                string s10="There are no playlists!";
                print_in_centre(s10);
            }
            else
            {
                int find=0;
                for(int i=0;i<MyPlaylists.size();i++)
                {
                    if(find_name==MyPlaylists[i].PLname())
                    {
                        find=1;
                        string s2="Playlist found at index = "+to_string(i);
                        print_in_centre(s2);
                        break;
                    }
                }
                if(find==0)
                {
                    string s3="--Playlist not found!--";
                    print_in_centre(s3);
                }
                cout<<"\n\n\n";
                just_display_playlists();
            }
            cout<<"\n\n";

            string s4="press any key to continue: ";
            print_in_centre(s4);
            getch();
        }
        
        void display_all_playlists()
        {
            system("cls");

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
                std::vector<std::string> lines = {
                    "Press [O] to open a playlist",
                    "Press [D] to delete a playlist",
                    "Press [E] to save and exit"
                };

                size_t maxWidth = 0;
                for (const std::string& s : lines) {
                    if (s.length() > maxWidth) {
                        maxWidth = s.length();
                    }
                }

                const int padding = 2;
                const int innerWidth = maxWidth + 2 * padding;

                std::string horizontalBorder = "+";
                horizontalBorder.append(innerWidth, '-');
                horizontalBorder += "+";

                std::cout << horizontalBorder << "\n";

                for (const std::string& line : lines) {
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
                
                string s1="==Displayling All Playlists==";
                print_in_centre(s1);
                cout<<"\n\n";

                int counter=0;
                for(auto& a:MyPlaylists)
                {
                    string s2="  "+a.PLname()+", Total Songs = "+to_string((a.want_playlist_songs()).size());
                    if(counter==i)
                    {
                        cout<<"->"<<s2;
                    }
                    else
                    {
                        cout<<"  "<<s2;
                    }
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
                    else
                    {
                        i--;
                    }
                }
                else if(c=='s')
                {
                    if(i==MyPlaylists.size()-1)
                    {
                        i=0;
                    }
                    else
                    {
                        i++;
                    }
                }
                else if(c=='o' || c=='O')
                {
                     manage_single_playlist(i);   
                }
                else if(c=='d' || c=='D')
                {
                    delete_by_index(i);
                }
                else if(c=='e'||c=='E')
                    break;
                system("cls");
            }
            cout<<"\n\n";
            string strin="press any key to continue: ";
            print_in_centre(strin);
            getch();
        }

        int ret_dis_play_index()
        {
            cout<<"\n\n";

            if(MyPlaylists.size()==0)
            {
                return -1;
            }
            int i=0;
            while(true)
            {
                int counter=0;
                for(auto& a:MyPlaylists)
                {
                    string s2="  "+a.PLname()+", Total Songs = "+to_string((a.want_playlist_songs()).size());
                    if(counter==i)
                    {
                        cout<<"->"<<s2;
                    }
                    else
                    {
                        cout<<"  "<<s2;
                    }
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
                    else
                    {
                        i--;
                    }
                }
                else if(c=='s')
                {
                    if(i==MyPlaylists.size()-1)
                    {
                        i=0;
                    }
                    else
                    {
                        i++;
                    }
                }
                else if(c == 13)
                {
                    return i;
                }
                else if(c=='e'||c=='E')
                    break;
                system("cls");
            }
            getch();
            return -1;
        }

        void delete_by_index(int index)
        {
            MyPlaylists.erase(MyPlaylists.begin()+index);
            cout<<"\n\n";
            string s2="Playlist successfully removed!";
            print_in_centre(s2);
        }

        void delete_playlist()
        {
            system("cls");

            if(MyPlaylists.size()==0)
            {
                string str="There are no playlists!";
                print_in_centre(str);
                cout<<"\n\n";
            }
            else
            {
                string s1="Select the playlist which you want to remove: ";
                print_in_centre(s1);
                cout<<"\n\n";

                int rem_index=ret_dis_play_index();

                MyPlaylists.erase(MyPlaylists.begin()+rem_index);
                cout<<"\n\n";

                string s2="Playlist successfully removed!";
                print_in_centre(s2);
                cout<<"\n\n";
            }
            string s3="Press any key to continue: ";
            print_in_centre(s3);
            getch();
        }

        void merge_playlists()
        {
            system("cls");

            string s1="Select 1st playlist to be merged: ";
            int m1,m2;
            print_in_centre(s1);
            cout<<"\n\n";
            m1=ret_dis_play_index();

            system("cls");

            string s2="Select 2nd playlist to be merged: ";
            print_in_centre(s2);
            cout<<"\n\n";
            m2=ret_dis_play_index();
            cout<<"\n\n\n";

            string s3="Enter Name Of merged Playlist: ";
            string playlist_name;
            print_in_centre(s3);
            getline(cin>>ws,playlist_name);

            Playlist merged_playlist(playlist_name);
            merged_playlist=MyPlaylists[m1]+MyPlaylists[m2];
            merged_playlist.changename(playlist_name);
            MyPlaylists.push_back(merged_playlist);

            cout<<"\n";
            string s4="--Merged Playlist successfully created!--";
            print_in_centre(s4);
            cout<<"\n\n\n";
            
            string s5="press any key to continue: ";
            print_in_centre(s5);
            getch();
        }
        
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
                        //remove_song_from_playlist();
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
                cout<<"\n";
                string stri="enter E/e to exit || any other key for playlists_operations page: ";
                char c;
                print_in_centre(stri);
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