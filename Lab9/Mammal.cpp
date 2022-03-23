/**
 * Filename: Mammal.cpp
 * Author: Anthony Grieco
 * Description: Creates the instantiation for the mammal class
 */

#include "Mammal.h"
#include <ostream>
using namespace std;

Mammal::Mammal(string name, int id, char gender, string hairColor, double normRegulatedTemp):Animal::Animal(name, id, gender) {
    this->hairColor = hairColor;
    this->normRegulatedTemp = normRegulatedTemp;
}

string Mammal::getHairColor() {
    return hairColor;
}

double Mammal::getRegTemp() {
    return normRegulatedTemp;
}

ostream &operator<<(ostream &os, const Mammal &m){
    os << "Name of Animal: "<< m.name << endl << "Phylum of Animal: " << m.phylum << endl << "ID of Animal: " << m.id << endl << "Gender: " << m.gender << endl << "Birthday: " << m.birthMonth << "/" << m.birthDay << "/" << m.birthYear << endl
    << "Hair Color: " << m.hairColor << endl << "Average Regulated Body Temperature: " << m.normRegulatedTemp << " F" << endl;

    return os;
}