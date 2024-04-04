/*
Author: Raymond Huang
Course: CSCI-135
Instructor: Gennady Maryash
Assignment: quiz13

function that creates member of n contains values n to 0;
*/
#include <iostream>
#include <vector>
using namespace std;

vector<int>makeVector(int n){
    vector<int> v;
    if(n>0){
        for(int i=n;i>-1;i--){
            v.push_back(i);
        }
    }
    return v;
}
/*int main(){
   vector<int>nums=makeVector
}*/