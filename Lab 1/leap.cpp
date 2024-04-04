/*
Author: Raymond Huang
Course: CSCI-135
Instructor: Gennady Maryash
Assignment: Lab1c

code prints if a year is a leap year or common year
*/

#include <iostream>
using namespace std;

int main(){
    int year;
    cout<<"enter a year: "<<endl;
    cin>>year;

    if(year%4==0&&year%100!=0||year%400==0){
        cout<<"leap year"<<endl;
    
    }
    else{
        cout<<"common year"<<endl;
    }

    
    return 0;
}