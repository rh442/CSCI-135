
/*
Author: Raymond Huang
Course: CSCI-135
Instructor: Gennady Maryash
Assignment: Lab10A

This code computes the distanc from a point to an origin in a 3D space
*/

#include <iostream>
using namespace std;

enum Genre {ACTION, COMEDY, DRAMA, ROMANCE, THRILLER};

class Time{   //create class Time with members hour and minute
public:
int hour;
int minute;
};
class Movie { 
public: 
    string title;
    Genre genre;     // only one genre per movie
    int duration;    // in minutes
};

class TimeSlot { 
public: 
    Movie movie;     // what movie
    Time startTime;  // when it starts
};

int minutesSinceMidnight(Time time){
    int hr=time.hour*60; // change hours to minutes
    int totalm = hr + time.minute;
    return totalm;
}
int minutesUntil(Time earlier, Time later){
    int diff = minutesSinceMidnight(later)-minutesSinceMidnight(earlier); // change both time to minutes and find the difference.
    return diff;
}
Time  addMinutes(Time time0, int min){
     Time time1;
     int tm = minutesSinceMidnight(time0) + min;
     int hr=tm/60;
     int mn=tm%60;
     time1.hour= hr;
     time1.minute= mn;
     return time1; 
     }
void printTimeSlot(TimeSlot ts){
    Time end= addMinutes(ts.startTime,ts.movie.duration);
    string g;
    switch (ts.movie.genre) {
        case ACTION   : g = "ACTION"; break;
        case COMEDY   : g = "COMEDY"; break;
        case DRAMA    : g = "DRAMA";  break;
        case ROMANCE  : g = "ROMANCE"; break;
        case THRILLER : g = "THRILLER"; break;
    }
    cout << ts.movie.title << " " << g << " (" << ts.movie.duration << " min)"<<"[starts at "<<ts.startTime.hour<<":"<<ts.startTime.minute<<", ends by"<<" "<<end.hour<<":"<<end.minute<<"]"<<endl;
    

}
TimeSlot scheduleAfter(TimeSlot ts, Movie nextMovie){
    Time end=addMinutes(ts.startTime,ts.movie.duration);
    TimeSlot after = {nextMovie,end};
    return after;

}
bool timeOverlap(TimeSlot ts1, TimeSlot ts2){
    Time after = addMinutes(ts1.startTime,ts1.movie.duration);
    int d0 =minutesSinceMidnight(ts1.startTime);
    int d1= minutesSinceMidnight(after);
    int d2= minutesSinceMidnight(ts2.startTime);
    if(d2==d0){
        return true;
    }
    else if(d2<d0){
         if(abs(d0-d2)>=ts2.movie.duration){
        return false;
    }
    else return true;
    }

    else if(abs(d2-d0)>=ts1.movie.duration){
        return false;
    }
    else{
        return true;
    }

}
int main(){
     Movie movie1 = {"Back to the Future", COMEDY, 180};
     Movie movie2 = {"Black Panther", ACTION, 63};
    Movie movie3 = {"Dungeons & Dragon: Honor Among Thieves",ACTION,134};
    
    TimeSlot morning = {movie1, {10, 30}};  
    TimeSlot daytime = {movie2, {8, 30}}; 
 
    cout<<timeOverlap( morning,  daytime);
    
}
