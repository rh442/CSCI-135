/*
Author: Raymond Huang
Course: CSCI-135
Instructor: Gennady Maryash
Assignment: Lab7B

code idents spaces
*/
 #include <iostream>
 
 
 using namespace std;
 int countChar(string line, char c){
    int x,len=line.length();
    for(int i=0;i<len;i++){
        if(line[i]==c){
            x++;
        }
    }
    return x;
 }
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
    int x=0;
    int y=0;
    int z=0;
    while(cin.good()){
        getline(cin,nl);
        if(removeLeadingSpaces(nl)[0]=='}'){
            for(int i=0;i<z-1;i++){
        cout<<'\t';

        }
        }
       else{
        for(int i=0;i<z;i++){
        cout<<'\t';
        }
    }
        
        cout<<removeLeadingSpaces(nl)<<endl;
        x=countChar(nl,'{');
        y=countChar(nl,'}');

        if(x>y){
            z+=x-y;
        }
        else if(x<y){
            z-=y-x;
        }
    


}

return 0;

}
   
