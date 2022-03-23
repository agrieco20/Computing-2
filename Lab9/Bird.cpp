/**
 * Filename: Bird.cpp
 * Author: Anthony Grieco
 * Description: Creates the instantiation for the bird class
 */

#include "Bird.h"
#include <ostream>
using namespace std;

Bird::Bird(string name, int id, char gender, string feathersColor, string boneType): Animal::Animal(name, id, gender){
    this->feathersColor = feathersColor;
    this->boneType = boneType;
}

string Bird::getFeatherColor() {
    return feathersColor;
}

string Bird::getBonesType() {
    return boneType;
}

ostream &operator<<(ostream &os, const Bird &b) {
    os << "Name of Animal: " << b.name << endl << "Phylum of Animal: " << b.phylum << endl << "ID of Animal: " << b.id << endl << "Gender: " << b.gender << endl << "Birthday: " << b.birthMonth << "/" << b.birthDay << "/" << b.birthYear << endl
       << "Feather Color: " << b.feathersColor << endl << "Bone Type: " << b.boneType << endl;

    return os;
}