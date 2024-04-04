/*
Author: Raymond Huang
Course: CSCI-135
Instructor: Gennady Maryash
Assignment: Project 3B

Decalration of trainer class
*/

#include <iostream>
#include <vector>
#include "profemon.hpp"
#ifndef trainer_HPP
#define trainer_HPP


class Trainer{
    protected:
    std::vector<Profemon> profedex;
    Profemon team[3];
    Profemon *profepointer;
    public:
    Trainer();
    Trainer(std::vector <Profemon> profemons);
    bool contains(std::string name);
    bool addProfemon(Profemon profemon);
    bool removeProfemon(std::string name);
    void setTeamMember(int slot, std::string name);
    bool chooseProfemon(int slot);
    Profemon getCurrent();
    void printProfedex();
    void printTeam();
};

#endif