/*
Author: Raymond Huang
Course: CSCI-135
Instructor: Gennady Maryash
Assignment: Project 3A

Definition of skill member functions
*/

#include<iostream>
#include "skill.hpp"

Skill::Skill(){
    Skill_name="Undefined";
    dscrpt="Undefined";
    use=-1;
    special=-1;
}
Skill::Skill(std::string name, std::string description, int specialty, int uses){
    Skill_name=name;
    dscrpt=description;
    use=uses;
    special=specialty;
}
std::string Skill::getName(){
    return Skill_name;
}
std::string Skill::getDescription(){
    return dscrpt;
}
int Skill::getTotalUses(){
    return use;
}
int Skill::getSpecialty(){
    return special;
}
void Skill::setName(std::string name){
    Skill_name=name;
}
void Skill::setDescription(std::string description){
    dscrpt=description;
}
void Skill::setTotalUses(int uses){
    use=uses;
}
bool Skill::setSpecialty(int specialty){
    if(specialty>=0&&specialty<=2){
        special=specialty;
        return true;
    }
    return false;
}
