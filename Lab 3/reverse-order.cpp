/*
Author: Raymond Huang
Course: CSCI-135
Instructor: Gennady Maryash
Assignment: Lab3A

This code prints out the east storage of the data table
*/

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <climits>
using namespace std;

int main(){
    string start,end;
    cout<<"Enter start: "<<'\n';
    cin>>start;
    cout<<"Enter start: "<<'\n';
    cin>>end;
    string date;
    string eastST,eastEL,WestST,WestEL;
    ifstream fin("Current_Reservoir_Levels.tsv");
    if(fin.fail()){
        cerr<<"file cannot be opened for reading."<<endl;
        exit(1);
    }
    string junk;
    getline(fin,junk);
    int count=0;
    while(fin>>date>>eastST>>eastEL>>WestST>>WestEL){
        if(date>=start&&date<=end){
           count=count+1;
           
        }

    }
    fin.close();
    string why[365];
   
    int i=0,j;
    ifstream fin2("Current_Reservoir_Levels.tsv");
    if(fin2.fail()){
        cerr<<"file cannot be opened for reading."<<endl;
        exit(1);
    }
   
    getline(fin2,junk);
    while(fin2>>date>>eastST>>eastEL>>WestST>>WestEL){
        if(date>=start&&date<=end){
            
                 why[i]={date+" "+WestEL+" ft"};
                i=i+1;
            
    }
    }
    for(j=count-1;j>-1;j--){
        cout<<why[j]<<'\n';
    }
    return 0;
}