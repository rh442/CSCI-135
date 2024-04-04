/*
Author: Raymond Huang
Course: CSCI-135
Instructor: Gennady Maryash
Assignment: Project 3B

Definition of trainer member functions
*/

#include<iostream>
#include "trainer.hpp"
#include "profemon.hpp"
using namespace std;


Trainer::Trainer(){
    profepointer=nullptr;
}
Trainer::Trainer(vector <Profemon> profemons){
    int pos=0;
   for(int i=0;i<3;i++){
        if(team[i].getName()=="Undefined"){
            team[i]=profemons[pos];
            pos++;
        }
   }
    for(int j=pos;j<profemons.size();j++){
        profedex.push_back(profemons[j]);
    }
   
    profepointer=&team[0];

}
bool Trainer::contains(string name){
    for(int i=0;i<3;i++){
        if(team[i].getName()==name){
            return true;
        }
    }
    for(int j=0;j<profedex.size();j++){
        if(profedex[j].getName()==name){
            return true;
        }
    }
    return false;
}

bool Trainer::addProfemon(Profemon profemon){
    if(contains(profemon.getName())){
        return false;
    }
    for(int i = 0; i < 3; i++)
	{
		if(team[i].getName() == "Undefined")
		{
			team[i] = profemon;
			return true;
		}
	}
	profedex.push_back(profemon);
	return true;
}
bool Trainer::removeProfemon(string name){
        if(contains(name)!=true){
        return false;
    }
    else{
        for(int i=0;i<3;i++){
        if(team[i].getName()==name){
            Profemon blank;
            team[i]=blank;
            return true;
        }
    }
    for(int j=0;j<profedex.size();j++){
        if(profedex[j].getName()==name){
            profedex[j] = profedex[profedex.size() - 1];
           for(int i=j;i<profedex.size();i++){
            profedex[i]=profedex[i+1];
           }
           profedex.pop_back();
            return true;
        }
    }
}
return false;
}
void Trainer::setTeamMember(int slot, string name){
   int pos = 0;
    for(int i = 0; i < profedex.size(); i++)
    {
        if(profedex[i].getName() == name)
        {
            pos = i;
				break;
        }
    }
    
    if(team[slot].getName() == "Undefined")
    {
        team[slot] = profedex[pos];
        
        profedex[pos] = profedex[profedex.size() - 1];
        for(int i = pos; i < profedex.size() - 1; i++)
        {
            profedex[i] = profedex[i + 1];
        }
        profedex.pop_back();
    }
    else
    {
        Profemon swap = team[slot];
        team[slot] = profedex[pos];
        profedex[pos] = swap;
    }
}


bool Trainer::chooseProfemon(int slot){
    if(team[slot].getName() == "Undefined")
	{
		return false;
	}
	profepointer = &team[slot];
	return true; 
}
Profemon Trainer::getCurrent(){
    return *profepointer;
}
void Trainer::printProfedex(){
    for(int i=0;i<profedex.size();i++){
        if(profedex[i].getName()!="Undefined"){
      profedex[i].printProfemon(true);
      cout<<"\n";
    }
    }
}
 void Trainer::printTeam(){
        for(int i=0;i<3;i++){
             if(team[i].getName()!="Undefined"){
            team[i].printProfemon(true);
            cout<<"\n";

        }
    }
 }

 