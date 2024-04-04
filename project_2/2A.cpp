/*
Author: Raymond Huang
Course: CSCI-135
Instructor: Gennady Maryash
Assignment: project2

This code keeps order of song in a playlist
*/
#include <iostream>
#include <fstream>
#include <stdlib.h>
using namespace std;

int g_curr_size = 2;
int g_number_of_songs = 0;
string junk;

string *g_song_names = new string[g_curr_size];
string *g_artist_names = new string[g_curr_size];
int *g_song_durations = new int[g_curr_size];
string *g_genres = new string[g_curr_size];

void allocateNew(){
    string *g_song_names2 = new string[g_curr_size*2];
    for(int i=0;i<g_curr_size;i++){
        g_song_names2[i]=g_song_names[i];
    }
    delete[] g_song_names;
    g_song_names=g_song_names2;
   

    string *g_artist_names2 = new string[g_curr_size*2];
    for(int i=0;i<g_curr_size;i++){
        g_artist_names2[i]=g_artist_names[i];
    }
    delete[] g_artist_names;
    g_artist_names=g_artist_names2;
   

    int *g_song_durations2 = new int[g_curr_size*2];
    for(int i=0;i<g_curr_size;i++){
        g_song_durations2[i]=g_song_durations[i];
    }
    delete[] g_song_durations;
    g_song_durations=g_song_durations2;
    

    string *g_genres2 = new string[g_curr_size*2];
    for(int i=0;i<g_curr_size;i++){
        g_genres2[i]=g_genres[i];
    }
    delete[] g_genres;
    g_genres=g_genres2;


    g_curr_size=g_curr_size*2;
    

}
void readSongs(string filename){
    ifstream playlist;
    playlist.open(filename);
    if(playlist.fail()){
        cerr<<"file cannot be opened for reading."<<endl;
        exit(1);
}

while(playlist){
    if(g_number_of_songs==g_curr_size){
        allocateNew();
    }
    getline(playlist,g_song_names[g_number_of_songs],':');
    getline(playlist,g_artist_names[g_number_of_songs],'-');
    getline(playlist,g_genres[g_number_of_songs],'-');
    playlist>>g_song_durations[g_number_of_songs];
    getline(playlist,junk,'\n');
    g_number_of_songs++;
    
  
}
g_number_of_songs=g_number_of_songs-1;

}
int main(){
    string name="playlist.txt";
    readSongs(name);
    cout<<g_curr_size;
    for(int i=0;i<16;i++)
    cout<<g_genres [i]<<endl;
    
    /*cout<<g_artist_names[i]<<endl;
    cout<<g_genres[i]<<endl;
    cout<<g_song_durations[i]<<endl;*/
    
}

