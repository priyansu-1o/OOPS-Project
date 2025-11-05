#include<iostream>
#include<vector>
#include "../Core/playlist.hpp"
#include "../models/songClass.hpp"
int main()
{
    vector<Playlist> p(10);
    for(auto& a:p){
        string x;
        cin>>x;
        a.changename(x);
    }
    for(int i=0;i<30;i++)
    {
        cout<<endl;
    }
    cout<<"Hi arpit";
}