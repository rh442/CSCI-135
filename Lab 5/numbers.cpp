/*
Author: Raymond Huang
Course: CSCI-135
Instructor: Gennady Maryash
Assignment: Lab5A

This code prints out if number A is divisble by num B
*/

#include <iostream>
using namespace std;




bool isDivisibleBy(int n,int d){
    if(d==0){
        return false;
    }
    else if(n%d==0){
        return true;
    }
    else{
        return false;
    }
   
}

bool isPrime(int n){
    if(n<=1){
        return false;
    }
    int num=0;
    
    for(int i=2;i<n;i++){
        if(isDivisibleBy(n,i)==true){
            num++;

        }
    }
    if(num>0){
        return false;
    }
    else{
        return true;
    }
}
int nextPrime(int n){
    int nex=n+1;
    while(isPrime(nex)==false){
        nex++;
    }
    return nex;
}

int countPrimes(int a ,int b){
    int countp=0;
    for(int j=a;j<=b;j++){
        if(isPrime(j)==true){
            countp++;
        }
    }
    return countp;
}

bool isTwinPrime(int n){
    if(isPrime(n)==true&&(isPrime(n-2)==true || isPrime(n+2)==true)){
        return true;
    }
    else{
        return false;
    }
}

int nextTwinPrime(int n){
    int nx=n+1;
    while(isTwinPrime(nx)==false){
        nx++;
    }
    return nx;
  
}
int largestTwinPrime(int a,int b){
    for(int k=b;k>a;k--){
        if(isTwinPrime(k)==true){
            return k;
        }

    }
    return -1;
}

int main(){
    cout<<nextTwinPrime(5);
}

