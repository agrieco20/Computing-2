/**
 * Filename: Animal.h
 * Author: Anthony Grieco
 * Description: Creates the declaration for the Animal class
 */

#ifndef LAB9_ANIMAL_H
#define LAB9_ANIMAL_H

#include <string>
using namespace std;

class Animal {
    protected: //Changed from "private" to be able to inherit from this class in "problem_2"
        int id;
        string phylum = "Chordate";

    public:
        string name;
        char gender;
        int birthYear = 2000; //Preset for convenience of testing the class
        int birthMonth = 1; //Preset for convenience of testing the class
        int birthDay = 1; //Preset for convenience of testing the class

        Animal(string, int, char);

        int getID();

        void setID(int);

        string getPhylum();
};

#endif //LAB9_ANIMAL_H