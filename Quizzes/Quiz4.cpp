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
    string color,hex;
       ifstream fin("data.txt");
    if(fin.fail()){
        cerr<<"file cannot be opened for reading."<<endl;
        exit(1);
    }
  
    while(fin>>color>>hex){
        cout<<color<<" "<<hex<<endl;
        }
        fin.close();
        return 0;
}