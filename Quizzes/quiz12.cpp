/*
Author: Raymond Huang
Course: CSCI-135
Instructor: Gennady Maryash
Assignment: quiz12

class customer that has name and unique id 
*/
#include <iostream>
using namespace std;

class Customer{
private:
    string name;
    string unique_id;
public:
    Customer();
    Customer(string name1,string unique_id1);
    string get_name();
    string get_unique_id();
    void set_name(string name1);
    void set_unique_id(string unique_id);
};
Customer::Customer(){
    name="";
    unique_id="";
}
Customer::Customer(string name1,string unique_id1){
    name=name1;
    unique_id=unique_id1;
}
string Customer::get_name(){
    return name;
}
string Customer::get_unique_id(){
    return unique_id;
}
void Customer::set_name(string name1){
    name=name1;

}
void Customer::set_unique_id(string unique_id1){
    unique_id=unique_id1;
}