/*
Author: Raymond Huang
Course: CSCI-135
Instructor: Gennady Maryash
Assignment: Lab1D

code prints the numbers of days a month has
*/

#include <iostream>
using namespace std;

int main(){
    int num,year;
    cout<<"Enter the year"<<endl;
    cin>>year;
    cout<<"enter a month (1-12):"<<endl;
    cin>>num;
   
    if (num==2){
        if(year%4==0&&year%100!=0||year%400==0){
            cout<<"29"<<endl;
        }
        else{
            cout<<"28"<<endl;
        }
    }

    
    else if (num<=7&&num!=2){
        if(num%2==0){
            cout<<"30";
        }
        else{
            cout<<"31";
        }
    }
    else if (num>7){
        if(num%2==0){
            cout<<"31";
        }
        else{
            cout<<"30";
        }
        
    }
    return 0;
}
