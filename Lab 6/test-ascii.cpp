/*
Author: Raymond Huang
Course: CSCI-135
Instructor: Gennady Maryash
Assignment: Lab6A

This code prints out the ascii of a given string
*/

#include <iostream>
using namespace std;

int main(){
    string s="";
    cout<<"enter string: ";
    getline(cin,s);
    int len=s.length();
    for(int i=0;i<len;i++){
        cout<<s[i]<<" "<<(int)s[i]<<'\n';
    }

}