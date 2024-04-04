/*
Author: Raymond Huang
Course: CSCI-135
Instructor: Gennady Maryash
Assignment: Lab11A

This code creates a social network
*/

#include <iostream>
using namespace std;

class Profile {
private:
    string username;
    string displayname;
public:
    // Profile constructor for a user (initializing 
    // private variables username=usrn, displayname=dspn)
    Profile(string usrn, string dspn);
    // Default Profile constructor (username="", displayname="")
    Profile();
    // Return username
    string getUsername();
    // Return name in the format: "displayname (@username)"
    string getFullName();
    // Change display name
    void setDisplayName(string dspn);
};
Profile::Profile(string usrn, string dspn){
    username=usrn;
    displayname=dspn;
}
Profile::Profile(){
    username="";
    displayname="";
}
string Profile::getUsername(){
    return username;
}
string Profile::getFullName(){
    string FName = displayname+"(@"+username+")";
    return FName;
}
void Profile::setDisplayName(string dspn){
    displayname=dspn;

}
struct Post{
  string username;
  string message;
};

class Network {
private:
  static const int MAX_USERS = 20; // max number of user profiles
  int numUsers;                    // number of registered users
  Profile profiles[MAX_USERS];     // user profiles array:
                               // mapping integer ID -> Profile
    bool following[MAX_USERS][MAX_USERS]; 

// Returns user ID (index in the 'profiles' array) by their username
  // (or -1 if username is not found)
  int findID (string usrn);
  static const int MAX_POSTS = 100;
 int numPosts;                    // number of posts
 Post posts[MAX_POSTS];           // array of all posts
public:
  // Constructor, makes an empty network (numUsers = 0)
  Network();
  // Attempts to sign up a new user with specified username and displayname
  // return true if the operation was successful, otherwise return false
  bool addUser(string usrn, string dspn);
   // Make 'usrn1' follow 'usrn2' (if both usernames are in the network).
 // return true if success (if both usernames exist), otherwise return false
 bool follow(string usrn1, string usrn2);
  void printDot();
   // Add a new post
 bool writePost(string usrn, string msg);
 // Print user's "timeline"
 void printTimeline(string usrn);

};


int Network::findID (string usrn){
    for(int i=0;i<numUsers;i++){
        if(profiles[i].getUsername()==usrn){
            return i;
        }
    }
    return -1;
}
Network::Network(){
    numPosts=0;
    numUsers=0;
    for(int i=0;i<MAX_USERS;i++){
        for(int j=0;j<MAX_USERS;j++){
            following[i][j]=false;
        }
    }
}
bool Network::addUser(string usrn,string dspn){
    if(numUsers>=MAX_USERS){
        return false;
    }
    else if(findID(usrn)==-1){
        for(int i=0;i<usrn.length();i++){
            if((48<=usrn[i]&&usrn[i]<=57)||(65<=usrn[i]&&usrn[i]<=90)||(97<=usrn[i]&&usrn[i]<=122)){
                continue;
                    
                    
                    }
        else{
        return false;
    }
    }
    profiles[numUsers]=Profile(usrn,dspn);
    numUsers++;   
    return true;
    }
    
        return false;
    
}
bool Network::follow(string usrn1, string usrn2){

    if(findID(usrn1)!=-1&&findID(usrn2)!=-1){
        following[findID(usrn1)][findID(usrn2)]=true;
        return true;

    }
    return false;
}

void Network::printDot(){
    cout<<"digraph {"<<endl;
    for(int i=0;i<numUsers;i++){
        cout<<"\"@"<<profiles[i].getUsername()<<"\""<<endl;
    }
    for(int i=0;i<numUsers;i++){
        for(int j=0;j<numUsers;j++){
            if(following[i][j]==true){
                cout<<"\"@"<<profiles[i].getUsername()<<"\" -> "<<"\"@"<<profiles[j].getUsername()<<"\""<<endl;
            }
                        
        }
    }
    cout<<"}";

}
bool Network::writePost(string usrn,string msg){
    if(findID(usrn)==-1||numPosts>=100){
        return false;
    }
    else{
        posts[numPosts]={usrn,msg};
        numPosts++;
        return true;
    }
}
void Network::printTimeline(string usrn){
    for(int i=numPosts;i>-1;i--){      
        
             if(posts[i].username==usrn){
                cout<<profiles[findID(usrn)].getFullName()<<":"<<posts[i].message<<endl;

             }
             for(int j=0;j<numUsers;j++){
             if(following[findID(usrn)][j]==true&&profiles[j].getUsername()==posts[i].username){
                cout<<profiles[j].getFullName()<<":"<<posts[i].message<<endl;
             }
        }
    }
}

int main() {
  Network nw;
  // add three users
  nw.addUser("mario", "Mario");
  nw.addUser("luigi", "Luigi");
  nw.addUser("yoshi", "Yoshi");
   
  nw.follow("mario", "luigi");
  nw.follow("luigi", "mario");
  nw.follow("luigi", "yoshi");
  nw.follow("yoshi", "mario");

  // write some posts
  nw.writePost("mario", "It's a-me, Mario!");
  nw.writePost("luigi", "Hey hey!");
  nw.writePost("mario", "Hi Luigi!");
  nw.writePost("yoshi", "Test 1");
  nw.writePost("yoshi", "Test 2");
  nw.writePost("luigi", "I just hope this crazy plan of yours works!");
  nw.writePost("mario", "My crazy plans always work!");
  nw.writePost("yoshi", "Test 3");
  nw.writePost("yoshi", "Test 4");
  nw.writePost("yoshi", "Test 5");

  cout << endl;
  cout << "======= Mario's timeline =======" << endl;
  nw.printTimeline("mario");
  cout << endl;

  cout << "======= Yoshi's timeline =======" << endl;
  nw.printTimeline("yoshi");
  cout << endl;
}
