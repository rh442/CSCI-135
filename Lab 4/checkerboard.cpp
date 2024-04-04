/*
Author: Raymond Huang
Course: CSCI-135
Instructor: Gennady Maryash
Assignment: Lab4B

This code out a checkerboard pattern
*/

#include <iostream>
using namespace std;

int main(){
    int height,width;
    cout<<"width: "<<endl;
    cin>>width;
    cout<<"height: ";
    cin>>height;
    int i,j;
    cout<<"Shape: "<<endl;
    for(i=0;i<height;i++){
        if(i%2==0){
            for(j=0;j<width;j++){
                if(j%2==0){
                    cout<<"*";
                }
                else if(j%2!=0){
                    cout<<" ";
                }
                

            }
            cout<<endl;
        }
        else if(i%2!=0){
            for(j=0;j<width;j++){
                if(j%2!=0){
                    cout<<"*";
                }
                else if(j%2==0){
                    cout<<" ";
                }
                

             }
             cout<<endl;
             }
    
    }
return 0;
}