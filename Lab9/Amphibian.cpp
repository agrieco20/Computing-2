/**
 * Filename: Amphibian.cpp
 * Author: Anthony Grieco
 * Description: Creates the instantiation for the amphibian class
 */

#include "Amphibian.h"
#include <ostream>
using namespace std;

Amphibian::Amphibian(string name, int id, char gender, string breathingMethod, string skinType): Animal::Animal(name, id, gender){
    this->breathingMethod = breathingMethod;
    this->skinType = skinType;
}

string Amphibian::getBreathing() {
    return breathingMethod;
}

string Amphibian::getSkinType() {
    return skinType;
}

ostream &operator<<(ostream &os, const Amphibian &a){
    os << "Name of Animal: "<< a.name << endl << "Phylum of Animal: " << a.phylum << endl << "ID of Animal: " << a.id << endl <<"Gender: " << a.gender << endl << "Birthday: " << a.birthMonth << "/" << a.birthDay << "/" << a.birthYear << endl
       << "Breathing Method: " << a.breathingMethod << endl << "Skin Type: " << a.skinType << endl;

    return os;
}