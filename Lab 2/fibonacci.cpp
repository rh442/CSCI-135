/*
Author: Raymond Huang
Course: CSCI-135
Instructor: Gennady Maryash
Assignment: Lab2D

code the fibonacci sequence
*/

#include <iostream>
using namespace std;

int main(){
    int fib[60];
    fib[0]=0;
    fib[1]=1;
    int i;
    for(i=0;i<60;i++){
        if(i>=2){
            fib[i]=fib[i-1]+fib[i-2];
            cout<<fib[i]<<endl;
        }
        else{
            cout<<fib[i]<<endl;
        }
    }
    return 0;
    
}
/*
The values start becoming negative when you near 2billion*/