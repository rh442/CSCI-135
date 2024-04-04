/*
Author: Raymond Huang
Course: CSCI-135
Instructor: Gennady Maryash
Assignment: Lab6c

code uses vignere cipher
*/
#include <iostream>
using namespace std;

string encryptVigenere(string plaintext, string keyword){
    int len=plaintext.length();
    int len2=keyword.length();
    string n="";
    int x=0;
    for(int i=0;i<len;i++){
    if(122>=(int)plaintext[i]&& (int)plaintext[i]>=97){
    n=n+char(((int)plaintext[i]-97+(keyword[(x)%len2]-97))%26+97);
    x++;
    
}
else if(90>=(int)plaintext[i]&& (int)plaintext[i]>=64){
    n=n+char(((int)plaintext[i]-65+(keyword[(x)%len2]-97))%26+65);
    x++;
}
else{
    n=n+plaintext[i];
    
}

    }
    return n;
}

int main(){
    cout<<encryptVigenere("Hello, World","cake");
}