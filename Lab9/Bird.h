/**
 * Filename: Bird.h
 * Author: Anthony Grieco
 * Description: Creates the declaration for the bird class
 */

#ifndef LAB9_BIRD_H
#define LAB9_BIRD_H

#include "Animal.h"
using namespace std;

class Bird: public Animal{
    private:
        string feathersColor;
        string boneType;

    public:
        Bird(string, int, char, string, string);
        friend ostream &operator<<(ostream &os, const Bird &m);

        string getFeatherColor();
        string getBonesType();
};

#endif //LAB9_BIRD_H