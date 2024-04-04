/*
Author: Raymond Huang
Course: CSCI-135
Instructor: Gennady Maryash
Assignment: Lab12A

This code returns only positive value
*/

#include <iostream>
#include <vector>
using namespace std;

vector<int> goodVibes(const vector<int> v){
    vector<int>nw;
    for(int i=0;i<v.size();i++){
    if(v[i]>0){
        nw.push_back(v[i]); 
    }
}
return nw;
}
int main(){
    
}
