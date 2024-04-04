/*
Author: Raymond Huang
Course: CSCI-135
Instructor: Gennady Maryash
Assignment: Lab4D

This code prints out the lower corner of a square
*/

#include <iostream>
using namespace std;

int main(){
    int length;
    cout<<"Input side length: ";
    cin>>length;
    int i,j;
    cout<<"Shape: "<<endl;
    for(i=0;i<length;i++){
        for(j=0;j<=i;j++){
            cout<<"*";
        }
        cout<<endl;
    }
    return 0;
}