/**
 * Filename: Animal.cpp
 * Author: Anthony Grieco
 * Description: Creates the instantiation for the Animal class
 */

#include "Animal.h"

using namespace std;

Animal::Animal(string name, int id, char gender){
    this->name = name;
    this->id = id;
    this->gender = gender;
    this->phylum = phylum;
}

int Animal::getID(){
    return id;
}

void Animal::setID(int newID){
    id = newID;
}

string Animal::getPhylum(){
    return phylum;
}