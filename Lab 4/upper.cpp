/*
Author: Raymond Huang
Course: CSCI-135
Instructor: Gennady Maryash
Assignment: Lab4E

This code prints out the lower corner of a square
*/

#include <iostream>
using namespace std;

int main(){
    int size;
    cout<<"Input size length: ";
    cin>>size;
    int i,j;
    cout<<"Shape: "<<endl;
    for(i=0;i<size;i++){
        for(j=0;j<size;j++){
            if(j<i){
                cout<<" ";
            }
            else{
                cout<<"*";
            }
        }
        cout<<endl;
    }
    return 0;
}