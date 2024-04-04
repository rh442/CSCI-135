/*
Author: Raymond Huang
Course: CSCI-135
Instructor: Gennady Maryash
Assignment: Project 3A

Definition of Profemon member functions
*/

#include<iostream>
#include "profemon.hpp"



Profemon::Profemon(){
    p_name="Undefined";
}
Profemon::Profemon(std::string name, double max_health, Specialty specialty){
    p_name=name;
    healthMax=max_health;
    SP=specialty;
    xp_to_next=50;
    p_level=0;
    current_xp=0;

}
std::string Profemon::getName(){
    return p_name;
}
Specialty Profemon::getSpecialty(){
    return SP;
}
int Profemon::getLevel(){
    return p_level;
}
double Profemon::getMaxHealth(){
    return healthMax;
}
void Profemon::setName(std::string name){
    p_name=name;
}
void Profemon::levelUp(int exp){
    int total_xp=current_xp+exp;
    int left;
    int new_xp;
    if(total_xp>=xp_to_next){
        p_level++;
        left=(total_xp-xp_to_next);
        switch(SP){
        case ML:
        xp_to_next=xp_to_next+10;
        break;
        case SOFTWARE:
        xp_to_next=xp_to_next+15;
        break;
        case HARDWARE:
        xp_to_next=xp_to_next+20;
        break;
        
    }
    current_xp=0;
    levelUp(left);
    
    }
    else{
        current_xp=total_xp;
    }
        
  

}
bool Profemon::learnSkill(int slot, Skill skill){
    if(slot<=2&&slot>=0&&skill.getSpecialty()==SP){
        skillz[slot]=skill;
        return true;

    }
    return false;
}
void Profemon::printProfemon(bool print_skills){
    
    std::string Spec;
    switch(SP){
        case ML:
        Spec="ML";
        break;
        case SOFTWARE:
        Spec="SOFTWARE";
        break;
        case HARDWARE:
        Spec="HARDWARE";
        break;
    }
    
    std::cout<<p_name<<" ["<<Spec<<"] "<<"| lvl "<<p_level<<" | exp "<<current_xp<<"/"<<xp_to_next<<" | hp "<<healthMax<<std::endl;
    if(print_skills==true){
    for(int i=0;i<3;i++){
        if(skillz[i].getName()!="Undefined"){
            std::cout<<"    "<<skillz[i].getName()<<" ["<<skillz[i].getTotalUses()<<"] : "<<skillz[i].getDescription()<<std::endl;


        }
    }
       }
   
}