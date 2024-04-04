/*
Author: Raymond Huang
Course: CSCI-135
Instructor: Gennady Maryash
Assignment: Lab3B

This code prints out the east storage of the data table
*/

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <climits>
using namespace std;

int main(){
    string date;
    double eastST,eastEL,WestST,WestEL;
    ifstream fin("Current_Reservoir_Levels.tsv");
    if(fin.fail()){
        cerr<<"file cannot be opened for reading."<<endl;
        exit(1);
    }
    string junk;
    double max=0,min=INT_MAX;
    getline(fin,junk);
    while(fin>>date>>eastST>>eastEL>>WestST>>WestEL){
        fin.ignore(INT_MAX,'\n');
        if(eastST>max){
            if (max<min){
                max=min;
            }
            max=eastST;
        }
        else if(eastST<min){
            min=eastST;
        }
    }
    cout<<"minimum storage in East basin: "<<min<<" "<<"billion gallons"<<'\n';
    cout<<"MAXimum storage in East basin: "<<max<<" "<<"billion gallons"<<'\n';
    return 0;
}

