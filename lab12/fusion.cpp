/*
Author: Raymond Huang
Course: CSCI-135
Instructor: Gennady Maryash
Assignment: Lab12A

This code combinens 2 vectors
*/

#include <iostream>
#include <vector>
using namespace std;

void gogeta(vector<int> &goku, vector<int> &vegeta){
    for(int i=0;i<vegeta.size();i++){
        goku.push_back(vegeta[i]);

    }
    vegeta.clear();
}