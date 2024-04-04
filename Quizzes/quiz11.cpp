/*
Author: Raymond Huang
Course: CSCI-135
Instructor: Gennady Maryash
Assignment: quiz11

class money that gets withdrawed from
*/

#include <iostream>
using namespace std;

class Money{
    public:
    int dollars;
    int cents;
};
Money withdraw_money(Money balance,Money withdrawal){
    Money rt;
    int BalanceCents = balance.dollars*100 + balance.cents;
    int BalanceWD= withdrawal.dollars*100 + withdrawal.cents;
    int difference = BalanceCents - BalanceWD;
    if(difference<=0){
        rt={0,0};
    }
    else{
        int d=difference/100;
        int c=difference%100;
        rt={d,c};
    }
    return rt;
}