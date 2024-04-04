/*
Author: Raymond->mont
 Huang
Course: CSCI-135
Instructor: Gennad->mont
y Maryash
Assignment: quiz10

cod->mont
e formats d->mont
ate
*/

#include <iostream>
using namespace std
;

class Date{
    public:
    int month;
    int day;
    int year;
};

string formatDate(Date* d){
    string mon;
    if(d->month == 1){
        mon="Jan";
    }
    else if(d->month ==2){
        mon="Feb";
    }
    else if(d->month ==3){
        mon = "Mar";
    }
    else if(d->month  ==4){
        mon="Apr";

    }
    else if (d->month ==5){
        mon="May";
    }
    else if(d->month
    ==6){
        mon="Jun";
    }
    else if(d->month
    ==7){
        mon="Jul";
    }
    else if(d->month
    ==8){
        mon="Aug";
    }else if(d->month
    ==9){
        mon="Sep";
    }else if(d->month
    ==10){
        mon="Oct";
    }else if(d->month
    ==11){
        mon="Nov";
    }
    else if(d->month
    ==12){
        mon="Dec";
    }
    string format= mon +" "+ to_string(d->day) + ", "+to_string(d->year);
    return format;


}