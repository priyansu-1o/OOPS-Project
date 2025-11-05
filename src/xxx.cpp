#include<bits/stdc++.h>
#include "models/songClass.hpp"
using namespace std;

void musicSort(vector<Song> s)
{
    cout<<"Enter How to Sort:"<<endl;
    cout<<"1.Title Ascending"<<endl;
    cout<<"2.Title Descending"<<endl;
    cout<<"3.Artist Name Ascending"<<endl;
    cout<<"4.Artist Name Descending"<<endl;
    cout<<"5.Duration Ascending"<<endl;
    cout<<"6.Duration Descending"<<endl;
    int c;
    cin>>c;
    switch(c)
    {
        case 1:
            sort(s.begin(), s.end(), [](const Song& a, const Song& b) {
            return a.getTitle() < b.getTitle();
            });
            break;
        case 2:
            sort(s.begin(), s.end(), [](const Song& a, const Song& b) {
            return a.getTitle() > b.getTitle();
            });
            break;
        case 3:
            sort(s.begin(), s.end(), [](const Song& a, const Song& b) {
            return a.getArtist() < b.getArtist();
            });
            break;
        case 4:
            sort(s.begin(), s.end(), [](const Song& a, const Song& b) {
            return a.getArtist() > b.getArtist();
            });
            break;
        case 5:
            sort(s.begin(), s.end(), [](const Song& a, const Song& b) {
            return a.getDuration() < b.getDuration();
            });
            break;
        case 6:
            sort(s.begin(), s.end(), [](const Song& a, const Song& b) {
            return a.getDuration() > b.getDuration();
            });
            break;
        default:
            cout<<"Invalid";
    }
}
