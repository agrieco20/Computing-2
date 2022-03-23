/**
 * Filename: problem_2.cpp
 * Author: Anthony Grieco
 * Description: Tests each of your derived classes and the methods in your derived class including the overloaded stream output method
 */

#include "Mammal.h"
#include "Bird.h"
#include "Fish.h"
#include "Reptile.h"
#include "Amphibian.h"
#include <iostream>

using namespace std;

int main() {
    Mammal human("Human [Mammal]", 1, 'M', "Brown", 98.6);
    Bird robin("Robin [Bird]", 2, 'F', "Red", "Hollow");
    Fish bass("Bass [Fish]", 3, 'M', 2, 5);
    Reptile crocodile("Crocodile [Reptile]", 4, 'M', "Cold", "Dry");
    Amphibian frog("Frog [Amphibian]", 5, 'F', "Cutaneous Respiration (Can Breathe Through Skin)", "Moist");

    cout << human;
    cout << "[Mammal Method Test] Hair Color: " << human.getHairColor() << endl; //Tests derived class method
    cout << "[Mammal Method Test] Average Regulated Body Temperature: " << human.getRegTemp() << endl; //Tests derived class method
    cout << endl;

    cout << robin;
    cout << "[Bird Method Test] Feather Color: "<< robin.getFeatherColor() << endl; //Tests derived class method
    cout << "[Bird Method Test] Bone Type: "<< robin.getBonesType() << endl; //Tests derived class method
    cout << endl;

    cout << bass;
    cout << "[Fish Method Test] Fin Number: " << bass.getFinNum() << endl; //Tests derived class method
    cout << "[Fish Method Test] Gill Number: " << bass.getGillNum() << endl; //Tests derived class method
    cout << endl;

    cout << crocodile;
    cout << "[Reptile Method Test] Blood Type: " << crocodile.getBloodType() << endl; //Tests derived class method
    cout << "[Reptile Method Test] Skin Type: " << crocodile.getSkinType() << endl; //Tests derived class method
    cout << endl;

    cout << frog;
    cout << "[Amphibian Method Test] Breathing Method: " << frog.getBreathing() << endl; //Tests derived class method
    cout << "[Amphibian Method Test] Skin Type: " << frog.getSkinType() << endl; //Tests derived class method
    cout << endl;

    return 0;
}