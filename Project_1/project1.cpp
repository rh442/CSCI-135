/*
Author: Raymond Huang
Course: CSCI-135
Instructor: Gennady Maryash
Assignment: Lab3B

This code prints out the east storage of the data table
*/

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <climits>
#include <stdlib.h>
using namespace std;

const int g_MAX_WORDS = 1000;
int g_word_count = 0;

string g_words[g_MAX_WORDS];
string g_definitions[g_MAX_WORDS];
string g_pos[g_MAX_WORDS];
string junk;
int l=0;

void readWords(string filename){
    ifstream fin(filename);
    if(fin.fail()){
        cerr<<"file cannot be opened for reading."<<endl;
        exit(1);
}

 
        while(fin.good()){
            getline(fin,g_words[g_word_count],' ');
            getline(fin,g_pos[g_word_count],' ');
            getline(fin,junk,' ');
            getline(fin,g_definitions[g_word_count],'\n');
            g_word_count++;
          
    }
    g_word_count=g_word_count-1;

}

int getIndex(string word){
    for(int i=0;i<g_MAX_WORDS;i++){
        if(g_words[i]==word){
            return i;
        }
    }
    return -1;  
}

string getDefinition(string word){
    if(getIndex(word)!=-1){
    return g_definitions[getIndex(word)];
    }
    else{
        return "NOT_FOUND";
    }
}

string getPOS(string word){
     if(getIndex(word)!=-1){
    return g_pos[getIndex(word)];
    }
    else{
        return "NOT_FOUND";
    }

}
int countPrefix(string prefix){
    int m=0;
    int len=prefix.length();
    for(int j=0;j<g_word_count;j++){
        if(g_words[j].substr(0,len)==prefix){
            m++;
        }

    }
    
    return m;
    
}

bool addWord(string word,string definition,string pos){
    for(int i=0;i<=g_word_count;i++){
        if(g_words[i]==word){
            return false;
        }
    }
       
            g_word_count++;
            g_words[g_word_count-1]=word;
            g_definitions[g_word_count-1]=definition;
            g_pos[g_word_count-1]=pos;
        
    
    return true;

}

bool editWord(string word,string definition,string pos){
     for(int i=0;i<=g_word_count;i++){
        if(g_words[i]==word){
            g_definitions[i]=definition;
            g_pos[i]=pos;
            return true;
        }
        
}
return false;
}
bool removeWord(string word){
    for(int i=0;i<=g_word_count;i++){
        if(g_words[i]==word){
            for(int j=i;j<=g_word_count;j++){
                g_words[j]=g_words[j+1];
                g_definitions[j]=g_definitions[j+1];
                g_pos[j]=g_pos[j+1];
            }
            g_word_count--;
            return true;
}
    }
    return false;
}
string getRandomWord() {
    srand((unsigned) time(NULL));
    int index = rand() % g_word_count;
    return g_words[index];
}
string maskWord(string word){
    string mask="";
    for(int i=0;i<word.length();i++){
        mask=mask+"_";
    }
    return mask;
}
int getTries(int difficulty){
    if(difficulty==0){
        return 9;
    }
    else if(difficulty==1){
        return 7;
    }
    else if(difficulty==2){
        return 5;
    }
    return 0;
}
void printAttempts(int tries, int difficulty){
    int t =getTries(difficulty);
    for(int i=0;i<tries;i++){
        cout<<"O";
    }
    for(int j=0;j<t-tries;j++){
        cout<<"X";
    }
    
}
bool revealLetter(string word, char letter, string &current){
    int ct=0;
    for(int i=0;i<word.length();i++){
        if(word[i]==letter){
            ct++;
            current[i]=letter;
        }
    }
    if(ct>0){
    return true;
}
else{
    return false;
}
}
void gameLoop() {
    int difficulty, tries;
    string word, current;
    char letter;
    while (true) {
        cout << "Welcome to Hangman!" << endl;
        cout <<  "0. easy\n1. normal\n2. hard\n3. exit\nChoose a difficulty: ";
        cin >> difficulty;
        while (difficulty < 0 || difficulty > 3) {
            cout <<  "Enough horseplay >_< !\n0. easy\n1. normal\n2. hard\n3. exit\nChoose a difficulty: ";
            cin >> difficulty;
        }
        if (difficulty == 3) {
            cout << "If you're hangry, go grab a bite! See what I did there?" << endl;
            break;
        }
        word = getRandomWord();
        current = maskWord(word);
        tries = getTries(difficulty);
        while (tries != 0) {
            cout << "Life: ";
            printAttempts(tries, difficulty);
            cout << endl << "Word: "<< current << endl;
            cout << "Enter a letter: ";
            cin >> letter;
            
            if (!revealLetter(word, letter, current)) {
                tries--;
            }
            if (current == word) {
                break;
            }
            if (tries == 2) {
                cout << "The part of speech of the word is "<< getPOS(word) << endl;
            }
            if (tries == 1) {
                cout << "Definition of the word: " << getDefinition(word) << endl;
            }
        }
        if (tries == 0) {
            cout << "The word is \"" << word << "\". Better luck next time! You're getting the ..ahem.. hang of it." << endl;
        }
        else {
            cout << "Congrats!!!" << endl;
        }
    }
}



int main(){
    string filename="dict.txt";
    readWords(filename);
    
   cout<<maskWord("mask");
}
