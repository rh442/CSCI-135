/*
Author: Raymond Huang
Course: CSCI-135
Instructor: Gennady Maryash
Assignment: Lab4G

This code out a checkerboard pattern
*/

#include <iostream>
using namespace std;

int main(){
    int w,h;
    cout<<" enter width and height: "<<endl;
    cin>>w>>h;
    int i,j;
    for(i=0;i<h;i++){
        if((i/3)%2==0){
            for(j=0;j<w;j++){
                if((j/3)%2==0){
                    cout<<"*";
                }
                else{
                    cout<<" ";
                }
                
            }
            cout<<endl;
        }
        else if((i/3)%2!=0){
            for(j=0;j<w;j++){
                if((j/3)%2==0){
                    cout<<" ";
                }
                else{
                    cout<<"*";
                }
                
            }
            cout<<endl;

        }
        }
        }