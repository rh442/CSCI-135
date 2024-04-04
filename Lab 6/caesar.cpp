/*
Author: Raymond Huang
Course: CSCI-135
Instructor: Gennady Maryash
Assignment: Lab6B

This code used the caesar cipher
*/
#include <iostream>
using namespace std;
char shiftChar(char c, int rshift){
    
    char ch;
    if(122>=(int)c&& (int)c>=97){
    ch=char(((int)c-97+rshift)%26+97);
    
}
else if(90>=(int)c&& (int)c>=64){
    ch=char(((int)c-65+rshift)%26+65);
}
else{
    return c;
}

return ch;
}
string encryptCaesar(string plaintext, int rshift){
    int len=plaintext.length();
    string nw="";
    for(int i =0;i<len;i++){
        
        nw=nw+(shiftChar(plaintext[i], rshift));
        

    }
    return nw;
}
int main(){
    string in1;
    int in2;
    cout<<"enter a string: ";
    getline(cin,in1);
    cout<<"enter shift: ";
    cin>>in2;
    cout<<encryptCaesar(in1,in2);
}