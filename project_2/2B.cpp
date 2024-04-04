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

string * getGenreSongs(string genre, int &genreCount){
    genreCount=0;
   string *song=new string[g_number_of_songs];
   for(int i=0;i<g_number_of_songs;i++){
    if(g_genres[i]==genre){
        song[genreCount]=g_song_names[i];
        genreCount=genreCount+1;
        
    }
   
   }
 
    return song;
}
string * getSongsFromDuration(int duration, int &durationsCount, int filter){ 
    durationsCount=0;
     string * song = new string[g_number_of_songs];
    if(filter==0){
        for(int i=0;i<g_number_of_songs;i++){
            if(g_song_durations[i]>duration){
                song[durationsCount]=g_song_names[i];
                durationsCount++;

            }
        }
        return song;
    }
    else if(filter==1){
         for(int i=0;i<g_number_of_songs;i++){
            if(g_song_durations[i]<duration){
                song[durationsCount]=g_song_names[i];
                durationsCount++;

            }
        }
        return song;

    }
     else if(filter==2){
         for(int i=0;i<g_number_of_songs;i++){
            if(g_song_durations[i]==duration){
                song[durationsCount]=g_song_names[i];
                durationsCount++;

            }
        }
        return song;

    }
   
    return song;
   
}
string* getUniqueArtists(int &uniqueCount){
    int i,j,k;
    
    if(g_number_of_songs==0){
        string *song=new string[g_number_of_songs];
        return song;
    }
    else{

  for(i=0;i<g_number_of_songs;i++){
    for(j=i+1;j<g_number_of_songs;j++){
      if(g_artist_names[i]==g_artist_names[j]){
        for(k=j;k<g_number_of_songs;k++){
          g_artist_names[k]=g_artist_names[k+1];
        }
        g_number_of_songs--;
        j--;
      }
    }
  }
  string *song=new string[g_curr_size];
  uniqueCount=0;
  for(i=0;i<g_number_of_songs;i++){
    song[uniqueCount]=g_artist_names[i];
    uniqueCount++;
  }
  
  return song;
}

}
string getFavoriteArtist(){
    if(g_number_of_songs==0){
        return "NONE";
    }
    else{
    string song=" ";
    int max=0,count=0,x=0;
    for(int i=0;i<g_curr_size;i++){
        for(int j=i;j<g_curr_size;j++){
            if(g_artist_names[i]==g_artist_names[j]){
                count++;
            }
        }
        if(count>max){
            song=g_artist_names[i];
            max=count;
        }
        count=0;

    }
    return song;
    }

}

int main(){
   string filename;
    filename="playlist.txt";
   readSongs(filename);
  cout<<g_number_of_songs<<endl;
  cout<<g_curr_size<<endl;

}