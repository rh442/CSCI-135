/*
Author: Raymond Huang
Course: CSCI-135
Instructor: Gennady Maryash
Assignment: Lab13A

This code prints numbers in a given range
*/

#include <iostream>
#include <cctype>
int sum=0;
int pos=-1;
void printRange(int a,int b){
    if(a<=b){
        std::cout<<a<<" ";
        printRange(a+1,b);

    }
    else{
        
    }
}
int sumRange(int left, int right){
    if(left<=right){
        sum=sum+left;
        sumRange(left+1,right); 
    }
    else{
        return sum;
    }
    return sum;
}
int sumArrayInRange(int *arr, int left, int right){

    if(left<=right){
        sum=sum+arr[left];
        sumArrayInRange(arr,left+1,right);

    }
    else{
        return sum;
    }
    return sum;
}
int sumArray(int *arr, int size){
    return sumArrayInRange(arr,0,size-1);
    

    
}
bool alpha(std::string s, int left, int right){
    if(left<=right){
        if(isalnum(s[left])){
            return true && alpha(s,left+1,right);


        }
        else{
            return false;
        }
    }
    else{
        return true;

    }
}
    
    
    

bool isAlphanumeric(std::string s){
    return alpha(s,0,s.size()-1);

}
bool np(int start,std::string s){
    int size =s.size();
    if(size==0){
        return true;
    }
    else if(size%2==1){

        return false;
    }
    else if(start<size/2){
        if(s[start]=='('&&s[(size-start-1)]==')'){
            return true && np(start+1,s);
        }
        else{
            return false;
        }
    }
    else{
        return true;
    }

  

}
bool nestedParens(std::string s){
    return np(0,s);
 
    
}

bool divisible(int *prices, int size){

}

int main(){
    
    std::cout<<nestedParens("(())");
}