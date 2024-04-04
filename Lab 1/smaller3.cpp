/*
Author: Raymond Huang
Course: CSCI-135
Instructor: Gennady Maryash
Assignment: Lab1B

code prints the smallest of 3 nummbers
*/

#include <iostream>
using namespace std;

int main(){
    int x,y,z;
    cout<<"enter a value: "<<endl;
    cin>>x;
    cout<<"enter a value: "<<endl;
    cin>>y;
    cout<<"enter a value: "<<endl;
    cin>>z;

    int small;
    if(x<y){
        if(x<z){
            small=x;
            cout<<small;
        }
        else{
            small=z;
            cout<<small;
        }
        
    }
    else if(x>y){
        if(y<z){
            small=y;
            cout<<y;
        }
        else{
            small=z;
            cout<<z;
        }
    }
    

    
}