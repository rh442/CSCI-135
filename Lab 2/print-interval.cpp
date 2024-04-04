/*
Author: Raymond Huang
Course: CSCI-135
Instructor: Gennady Maryash
Assignment: Lab2B

code prints the range of numbers in an array
*/

#include <iostream>
using namespace std;

int main(){
    int L,U,i;
    cout<<"Enter lower range(L)"<<endl;
    cin>>L;
    cout<<"Enter upper range(U)"<<endl;
    cin>>U;
    for(i=L;i<U;i++){
        cout<<i<<" ";
    }
    return 0;
}