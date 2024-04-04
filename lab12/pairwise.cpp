/*
Author: Raymond Huang
Course: CSCI-135
Instructor: Gennady Maryash
Assignment: Lab12A

This code returns pairwise sum or two vectors*/

#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

vector<int> sumPairWise(vector<int> &v1, vector<int> &v2){
    int diff=v1.size()-v2.size();
    int siz=v1.size();
    if(diff>0){
        siz=v1.size();
        for(int i=0;i<diff;i++){
            v2.push_back(0);
        }
    }
    else if(diff<0){
        siz=v2.size();
        for(int i=0;i<abs(diff);i++){
            v1.push_back(0);
        }
    }

    vector<int> v;
    for(int i=0;i<siz;i++){
        v.push_back(v1[i]+v2[i]);
    }
    return v;

    }
    