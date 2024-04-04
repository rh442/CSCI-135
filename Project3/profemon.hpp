/*
Author: Raymond Huang
Course: CSCI-135
Instructor: Gennady Maryash
Assignment: Project 3A

Declaration of Profemon member functions
*/

#include <iostream>
#ifndef profemon_HPP
#define profemon_HPP
#include "skill.hpp"

enum Specialty{ML,SOFTWARE,HARDWARE};
class Profemon{
    private:
    std::string p_name;
    int p_level;
    int xp_to_next;
    int current_xp;
    double healthMax;
    Specialty SP;
    Skill skillz[3];
    public:
    Profemon();
    Profemon(std::string name, double max_health, Specialty specialty);
    std::string getName();
    Specialty getSpecialty();
    int getLevel();
    double getMaxHealth();
    void setName(std::string name);
    void levelUp(int exp);
    bool learnSkill(int slot, Skill skill);
    void printProfemon(bool print_skills);
};


#endif