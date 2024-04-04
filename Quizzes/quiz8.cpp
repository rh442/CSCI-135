/*
Author: Raymond Huang
Course: CSCI-135
Instructor: Gennady Maryash
Assignment: Quiz8

This code returns the number of unbalnnces brackets
*/

#include <iostream>
using namespace std;

int unbalanced_brackets(string input){
    int len=input.length();
    int open=0,close=0;
    for(int i=0;i<len;i++){
        if(input[i]=='{'){
            open++;
        }
        else if(input[i]=='}'){
            close++;
        }
    }
    int ret=open-close;
    return ret;

}
