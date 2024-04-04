/*
Author: Raymond Huang
Course: CSCI-135
Instructor: Gennady Maryash
Assignment: quiz6

code makes a functions that takes the largest number out of 3 integers.
*/

#include <iostream>
using namespace std;

int max3(int a, int b, int c){
    int d=max(a,b);
    int e=max(b,c);
    int f=max(d,e);
    return f;
}

int main(){
    int a=1,b=21,c=3;
   cout<< max3(a,b,c);
}