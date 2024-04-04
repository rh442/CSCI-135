/*
Author: Raymond Huang
Course: CSCI-135
Instructor: Gennady Maryash
Assignment: Lab3C

This code which storage has the larger volume in the interval dates.
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
    double eastST,eastEL,WestST,WestEL;
    ifstream fin("Current_Reservoir_Levels.tsv");
    if(fin.fail()){
        cerr<<"file cannot be opened for reading."<<endl;
        exit(1);
    }
    string junk;
    getline(fin,junk);
    while(fin>>date>>eastST>>eastEL>>WestST>>WestEL){
        if(date>=start&&date<=end){
            if(eastEL<WestEL){
                cout<<date<<" "<<"West"<<'\n';
            }
            else if(eastEL>WestEL){
                cout<<date<<" "<<"East"<<'\n';
            }
            else{
                cout<<date<<" "<<"Equal"<<'\n';
            }
        }
    }
    }