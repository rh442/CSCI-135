/*
Author: Raymond Huang
Course: CSCI-135
Instructor: Gennady Maryash
Assignment: Lab1A

code prints the smallest of 2 nummbers
*/

#include <iostream>
using namespace std;

int main(){
    int x,y;
    cout<<"enter a number: "<<endl;
    cin>>x;
    cout<< "enter a second number: "<<endl;
    cin>>y;

    if(x<y){
        cout<<x<<endl;

    }
    else{
        cout<<y<<endl;
    }

    
    return 0;
}