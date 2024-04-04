/*
Author: Raymond Huang
Course: CSCI-135
Instructor: Gennady Maryash
Assignment: Lab12A

This code creates vector that  returns vector from 0 to n-1;
*/

#include <iostream>
#include <vector>
using namespace std;

vector<int>makeVector(int n){
    vector<int> v;
    for(int i=0;i<n;i++){
        v.push_back(i);
    }
    return v;
}
int main(){
    int n;
    makeVector(n);
}