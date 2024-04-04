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
    string user;
    cout<<"Enter date: "<<'\n';
    cin>>user;
    string date;
    double eastST,eastEL,WestST,WestEL;
    ifstream fin("Current_Reservoir_Levels.tsv");
    if(fin.fail()){
        cerr<<"file cannot be opened for reading."<<endl;
        exit(1);
    }
    string junk,in;
    getline(fin,junk);
    while(fin>>date>>eastST>>eastEL>>WestST>>WestEL){
        fin.ignore(INT_MAX,'\n');
        if(date==user){
            cout<<"East Basin Storage: "<<eastST<<" "<<"billion gallons"<<'\n';
        }
        
    }
    return 0;
}