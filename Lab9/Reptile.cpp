/**
 * Filename: Reptile.cpp
 * Author: Anthony Grieco
 * Description: Creates the instantiation for the reptile class
 */

#include "Reptile.h"
#include <ostream>
using namespace std;

Reptile::Reptile(string name, int id, char gender, string bloodType, string skinType):Animal::Animal(name, id, gender){
    this->bloodType = bloodType;
    this->skinType = skinType;
}

string Reptile::getBloodType() {
    return bloodType;
}

string Reptile::getSkinType() {
    return skinType;
}

ostream &operator<<(ostream &os, const Reptile &r){
    os << "Name of Animal: "<< r.name << endl << "Phylum of Animal: " << r.phylum << endl << "ID of Animal: " << r.id << endl <<"Gender: " << r.gender << endl << "Birthday: " << r.birthMonth << "/" << r.birthDay << "/" << r.birthYear << endl
       << "Blood Type: " << r.bloodType << endl << "Skin Type: " << r.skinType << endl;

    return os;
}