/*
Author: Raymond Huang
Course: CSCI-135
Instructor: Gennady Maryash
Assignment: quiz5

This code prints a 6 by 5 box
*/
#include <iostream>
using namespace std;

int main(){
    for(int i=0;i<6;i++){
        for(int j=0;j<5;j++){
            cout<<"+";
        }
        cout<<endl;
    }
}