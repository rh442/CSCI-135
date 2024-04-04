/*
Author: Raymond Huang
Course: CSCI-135
Instructor: Gennady Maryash
Assignment: quiz2

This code prints the bigger number
*/

#include <iostream>
using namespace std;

int main(){
    int x,y;
    cout<<"enter number #1:";
    cin>>x;
    cout<<"enter number #2:";
    cin>>y;
    cout<<max(x,y);
    return 0;
}
