/*
Author: Raymond Huang
Course: CSCI-135
Instructor: Gennady Maryash
Assignment: Project 3B

Definition of trainer member functions
*/

#include<iostream>
#include<vector>
#include "department.hpp"

MLDepartment::MLDepartment(std::vector<Profemon> profemons){
    for(int i=0;i<profemons.size();i++){
        if(profemons[i].getSpecialty()==0){
            addProfemon(profemons[i]);
    }
    }
}
bool MLDepartment::addProfemon(Profemon profemon){
        if(profemon.getSpecialty()==0){
           return Trainer::addProfemon(profemon);
        }

}
SoftwareDepartment::SoftwareDepartment(std::vector<Profemon> profemons){
    for(int i=0;i<profemons.size();i++){
        if(profemons[i].getSpecialty()==1){
             addProfemon(profemons[i]);
        }
    }

}
bool SoftwareDepartment::addProfemon(Profemon profemon){
        if(profemon.getSpecialty()==1){
          return Trainer::addProfemon(profemon);
        }

}
HardwareDepartment::HardwareDepartment(std::vector<Profemon> profemons){
    for(int i=0;i<profemons.size();i++){
        if(profemons[i].getSpecialty()==2){
            addProfemon(profemons[i]);
}
    }
}
bool HardwareDepartment::addProfemon(Profemon profemon){
        if(profemon.getSpecialty()==2){
           return Trainer::addProfemon(profemon);
        }

}