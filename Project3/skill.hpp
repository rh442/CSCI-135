/*
Author: Raymond Huang
Course: CSCI-135
Instructor: Gennady Maryash
Assignment: Project 3A

Decalration of skill member functions
*/

#include <iostream>
#ifndef skill_HPP
#define skill_HPP

class Skill{
    private:
    std::string Skill_name;
    std::string dscrpt;
    int use;
    int special;
    public:
    Skill();
    Skill(std::string name, std::string description, int specialty, int uses);
    std::string getName();
    std::string getDescription();
    int getTotalUses();
    int getSpecialty();
    void setName(std::string name);
    void setDescription(std::string description);
    void setTotalUses(int uses);
    bool setSpecialty(int specialty);
};


#endif