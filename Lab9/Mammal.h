/**
 * Filename: Mammal.h
 * Author: Anthony Grieco
 * Description: Creates the declaration for the mammal class
 */

#ifndef LAB9_MAMMAL_H
#define LAB9_MAMMAL_H

#include "Animal.h"
using namespace std;

class Mammal: public Animal{
    private:
        string hairColor;
        double normRegulatedTemp;

    public:
        Mammal(string, int, char, string, double);
        friend ostream &operator<<(ostream &os, const Mammal &m);

        string getHairColor();
        double getRegTemp();
};

#endif //LAB9_MAMMAL_H