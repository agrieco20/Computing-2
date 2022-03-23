/**
 * Filename: Amphibian.h
 * Author: Anthony Grieco
 * Description: Creates the declaration for the amphibian class
 */

#ifndef LAB9_AMPHIBIAN_H
#define LAB9_AMPHIBIAN_H

#include "Animal.h"
using namespace std;

class Amphibian: public Animal{
    private:
        string breathingMethod;
        string skinType;


    public:
        Amphibian(string, int, char, string, string);
        friend ostream &operator<<(ostream &os, const Amphibian &m);

        string getBreathing();
        string getSkinType();
};

#endif //LAB9_AMPHIBIAN_H