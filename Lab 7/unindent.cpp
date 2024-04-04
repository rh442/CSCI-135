/*
Author: Raymond Huang
Course: CSCI-135
Instructor: Gennady Maryash
Assignment: Lab7A

code unidents spaces
*/

 #include <iostream>
 #include <cctype>
 
 using namespace std;

string removeLeadingSpaces(string line){
    int len=line.length();
    string newline="";
    int start;
    for(int i=0;i<len;i++){
        if(isspace(line[i])){
            continue;
        }
        else{
        start=i;
        break;
        }
        
    }
    
    for(int j=start;j<len;j++){
        newline=newline+line[j];
    }

    return newline;
}

        

int main(){
    string in,nl;
    while(cin.good()){
        getline(cin,nl);
        cout<<removeLeadingSpaces(nl)<<endl;
}
return 0;


    }
   