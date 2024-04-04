/*
Author: Raymond Huang
Course: CSCI-135
Instructor: Gennady Maryash
Assignment: Quiz7

This code creates a function that removes e from a string.
*/

#include <iostream>
using namespace std;

void remove_e(string &sent){
    int len=sent.length();
    string nw=" ";
    for(int i=0;i<len;i++){
        if(sent[i]=='e'){
            nw=nw+"";
    }
    else{
        nw=nw+sent[i];
    }
    }
    sent=nw;
}

int main(){
    string str="cheese";
    remove_e(str);
    cout<<str;
}