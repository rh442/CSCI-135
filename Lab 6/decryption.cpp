/*
Author: Raymond Huang
Course: CSCI-135
Instructor: Gennady Maryash
Assignment: Lab6C

code decrypts caesar and vigenere
*/
#include <iostream>
using namespace std;

string encryptVigenere(string ciphertext, string keyword){
    int len=ciphertext.length();
    int len2=keyword.length();
    string n="";
    int x=0;
    for(int i=0;i<len;i++){
    if(122>=(int)ciphertext[i]&& (int)ciphertext[i]>=97){
    n=n+char(((int)ciphertext[i]-97+(keyword[(x)%len2]-97))%26+97);
    x++;
    
}
else if(90>=(int)ciphertext[i]&& (int)ciphertext[i]>=64){
    n=n+char(((int)ciphertext[i]-65+(keyword[(x)%len2]-97))%26+65);
    x++;
}
else{
    n=n+ciphertext[i];
    
}

    }
    return n;
}



char dshiftChar(char c, int rshift){
    
    char ch;
    if(122>=(int)c&& (int)c>=97){
    ch=char(((int)c-97+26-rshift)%26+97);
    
}
else if(90>=(int)c&& (int)c>=64){
    ch=char(((int)c-65+26-rshift)%26+65);
}
else{
    return c;
}

return ch;
}
string decryptCaesar(string ciphertext,int rshift){
    int len=ciphertext.length();
    string nw="";
    for(int i =0;i<len;i++){
        
        nw=nw+(dshiftChar(ciphertext[i], rshift));
        

    }
    return nw;

}
string decryptVigenere(string ciphertext,string keyword){
    int len=ciphertext.length();
    int len2=keyword.length();
    string n="";
    int x=0;
    for(int i=0;i<len;i++){
    if(122>=(int)ciphertext[i]&& (int)ciphertext[i]>=97){
    n=n+char(((int)ciphertext[i]-97+26-(keyword[(x)%len2]-97))%26+97);
    x++;
    
}
else if(90>=(int)ciphertext[i]&& (int)ciphertext[i]>=64){
    n=n+char(((int)ciphertext[i]-65+26-(keyword[(x)%len2]-97))%26+65);
    x++;
}
else{
    n=n+ciphertext[i];
    
}

    }
    return n;


}

int main(){
   /*cout<< decryptCaesar("Rovvy, Gybvn!", 10);
   cout<<decryptVigenere("Jevpq, Wyvnd!", "cake");*/
}