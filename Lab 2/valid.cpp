/*
Author: Raymond Huang
Course: CSCI-135
Instructor: Gennady Maryash
Assignment: Lab2A

code prints the square of a number from 0-100
*/

#include <iostream>
using namespace std;

int main(){
    int num;
    cout<<"Enter a number from 0-100"<<endl;
    cin>>num;
    while(num<=0||num>=100){
        cout<<"Enter a number from 0-100"<<endl;
        cin>>num;
    }
    int square;
    square=num*num;
    cout<<square;
    return 0;
}