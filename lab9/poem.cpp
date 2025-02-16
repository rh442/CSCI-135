/*
Author: Raymond Huang
Course: CSCI-135
Instructor: Gennady Maryash
Assignment: Lab9D

This code deletes dynamically allocated memory when they are no longer needed
*/


#include <iostream>
using namespace std;

string * createAPoemDynamically() {
    string *p = new string;
    *p = "Roses are red, violets are blue";
    return p;
}

int main() {
    while(true) {
        string *p;
        p = createAPoemDynamically();
        

       delete p; // assume that the poem p is not needed at this point

    }
}