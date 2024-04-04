/*
Author: Raymond Huang
Course: CSCI-135
Instructor: Gennady Maryash
Assignment: project2

This code keeps A and B in a class
*/
#include <iostream>
#include <fstream>
#include <stdlib.h>
using namespace std;



class Song{
    public:

    string name;
    string name1,name2;
    
    string artist;
    int duration;
    string genre;

};
int g_capacity = 2;
int g_size = 0;
string junk;
Song *g_songs = new Song[g_capacity];

void allocateNew(){
   Song *big= new Song[g_capacity*2];
    for(int i=0;i<g_capacity;i++){
        big[i].name=g_songs[i].name;
        big[i].artist=g_songs[i].artist;
        big[i].genre=g_songs[i].genre;
        big[i].duration=g_songs[i].duration;
    }
    delete[] g_songs;
    g_songs=big;
    g_capacity=g_capacity*2;

}
void readSongs(string filename){
  ifstream playlist;
    playlist.open(filename);
    if(playlist.fail()){
        cerr<<"file cannot be opened for reading."<<endl;
        exit(1);
}
while(playlist){
     if(g_size==g_capacity){
        allocateNew();
    }
   
    getline(playlist,g_songs[g_size].name,':');
    getline(playlist,g_songs[g_size].artist,'-');
    getline(playlist,g_songs[g_size].genre,'-');
    playlist>>g_songs[g_size].duration;
    getline(playlist,junk,'\n');
    g_size++;

}
g_size=g_size-1;
}
Song * getGenreSongs(string genre, int &genreCount){
    Song * song = new Song[g_size];
    genreCount=0;
   for(int i=0;i<g_size;i++){
    if(g_songs[i].genre==genre){
        song[genreCount].name=g_songs[i].name;
        song[genreCount].artist=g_songs[i].artist;
        song[genreCount].duration=g_songs[i].duration;
        song[genreCount].genre=g_songs[i].genre;
        genreCount++;  
    }
   }
    return song;
}

Song * getSongsFromDuration(int duration, int &durationsCount, int filter){ 
   
    durationsCount=0;
     Song * song = new Song[g_size];
    if(filter==0){
        for(int i=0;i<g_size;i++){
            if(g_songs[i].duration>duration){
                song[durationsCount].name=g_songs[i].name;
                song[durationsCount].artist=g_songs[i].artist;
                song[durationsCount].genre=g_songs[i].genre;
                song[durationsCount].duration=g_songs[i].duration;
                durationsCount++;

            }
        }
        return song;
    }
    else if(filter==1){
         for(int i=0;i<g_size;i++){
            if(g_songs[i].duration<duration){
                song[durationsCount].name=g_songs[i].name;
                song[durationsCount].artist=g_songs[i].artist;
                song[durationsCount].genre=g_songs[i].genre;
                song[durationsCount].duration=g_songs[i].duration;
                durationsCount++;

            }
        }
        return song;

    }
     else if(filter==2){
         for(int i=0;i<g_size;i++){
            if(g_songs[i].duration==duration){
                song[durationsCount].name=g_songs[i].name;
                song[durationsCount].artist=g_songs[i].artist;
                song[durationsCount].genre=g_songs[i].genre;
                song[durationsCount].duration=g_songs[i].duration;
                durationsCount++;

            }
        }
        return song;

    }
   
    return song;
   
}

string* getUniqueArtists(int &uniqueCount){
    
    int i,j,k;
    if(g_size==0){
        string *song=new string[g_size];
        return song;
    }
    else{

  for(i=0;i<g_size;i++){
    for(j=i+1;j<g_size;j++){
      if(g_songs[i].artist==g_songs[j].artist){
        for(k=j;k<g_size;k++){
          g_songs[k].artist=g_songs[k+1].artist;
        }
        g_size--;
        j--;
      }
    }
  }
  string *song=new string[g_capacity];
  uniqueCount=0;
  for(i=0;i<g_size;i++){
    song[uniqueCount]=g_songs[i].artist;
    uniqueCount++;
  }
  
  return song;
}

}
string getFavoriteArtist(){
    if(g_size==0){
        return "NONE";
    }
    else{
    string song=" ";
    int max=0,count=0,x=0;
    for(int i=0;i<g_capacity;i++){
        for(int j=i;j<g_capacity;j++){
            if(g_songs[i].artist==g_songs[j].artist){
                count++;
            }
        }
        if(count>max){
            song=g_songs[i].artist;
            max=count;
        }
        count=0;

    }
    return song;
    }

}

int main(){
    
string filename="playlist.txt";
readSongs(filename);
int count1,count2,count3;
getGenreSongs("Pop",count1);
cout<<count1<<endl;
cout<<g_size<<endl<<g_capacity;

   
}
