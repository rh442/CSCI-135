/*
Author: Raymond Huang
Course: CSCI-135
Instructor: Gennady Maryash
Assignment: quiz3

code prints out numbers from 1-10 through an array
*/

#include <iostream>
using namespace std;

int main(){
    int x[10];
    int i;
    for(i=0;i<10;i++){
        x[i]=i+1;
        cout<<x[i]<<endl;
    }
    return 0;
}