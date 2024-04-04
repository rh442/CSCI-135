/*
Author: Raymond Huang
Course: CSCI-135
Instructor: Gennady Maryash
Assignment: Lab4E

code prints an upside down trapezoid
*/
#include <iostream>
using namespace std;
int main(){
    int width,height;

    cout<< "enter width and height: "<<'\n';
    cin>>width>>height;
    cout<<"Shape: "<<endl;
    if((width-2*(height-1))>0){
    int i,j,k,l;
    for(i=0;i<height;i++){
        for(j=0;j<i;j++){
            cout<<" ";
        }
        for(k=0;k<width-2*i;k++){
            cout<<"*";
        }
        for(l=0;l<i;l++){
            cout<<" ";

    }
        cout<<'\n';
    }
    }
    else{
        cout<<"impossible shape!"<<endl;
    }

}