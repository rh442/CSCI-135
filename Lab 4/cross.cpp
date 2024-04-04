/*
Author: Raymond Huang
Course: CSCI-135
Instructor: Gennady Maryash
Assignment: Lab4C

This code out a cross pattern of user's size
*/

#include <iostream>
using namespace std;

int main(){
    int size;
    cout<<"size: ";
    cin>>size;
    int i,j;
    cout<<"size: "<<endl;
    for(i=0;i<size;i++){
        for(j=0;j<size;j++){
            if(i==j||size-1-i==j){
                cout<<"*";
            }
            else{
                cout<<" ";
            }
        }
        cout<<endl;
    }
    return 0;
}