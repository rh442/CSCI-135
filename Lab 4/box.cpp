/*
Author: Raymond Huang
Course: CSCI-135
Instructor: Gennady Maryash
Assignment: Lab4A

This code out a box
*/

#include <iostream>
using namespace std;

int main(){
    int width,height;
    cout<<"enter width: "<<endl;
    cin>>width;
    cout<<"enter height: "<<endl;
    cin>>height;
    int i,j;
    for(i=0;i<height;i++){
        for(j=0;j<width;j++){
            cout<<"*";
        }
        cout<<endl;
    }
    return 0;
}