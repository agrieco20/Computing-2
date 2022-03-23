/**
 * Filename: Fish.cpp
 * Author: Anthony Grieco
 * Description: Creates the instantiation for the fish class
 */

#include "Fish.h"
#include <ostream>
using namespace std;

Fish::Fish(string name, int id, char gender, int finNum, int gillNum): Animal::Animal(name, id, gender){
    this->finNum = finNum;
    this->gillNum = gillNum;
}

int Fish::getFinNum() {
    return finNum;
}

int Fish::getGillNum() {
    return gillNum;
}

ostream &operator<<(ostream &os, const Fish &f){
    os << "Name of Animal: "<< f.name << endl << "Phylum of Animal: " << f.phylum << endl << "ID of Animal: " << f.id << endl << "Gender: " << f.gender << endl << "Birthday: " << f.birthMonth << "/" << f.birthDay << "/" << f.birthYear << endl
       << "Fin Number: " << f.finNum << endl << "Gill Num: " << f.gillNum << endl;

    return os;
}