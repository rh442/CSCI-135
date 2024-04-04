/*
Author: Raymond Huang
Course: CSCI-135
Instructor: Gennady Maryash
Assignment: Lab2c

code allows user to edit a array
*/

#include <iostream>
using namespace std;

int main(){
    int myData[10];
    int i,I,V;
    for(i=0;i<10;i++){
        myData[i]=1;
    }
    do{
        for(i=0;i<10;i++){
            cout<<myData[i]<<" ";
        }
        cout<<endl;
        cout<<"enter index";
        cin>>I;
        cout<<"enter value";
        cin>>V;
        if(I>=0&&I<10){
            myData[I]=V;
        }

    }while(I>=0&&I<10);
}  
