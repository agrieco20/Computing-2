/**
 * Filename: Reptile.h
 * Author: Anthony Grieco
 * Description: Creates the declaration for the reptile class
 */

#ifndef LAB9_REPTILE_H
#define LAB9_REPTILE_H

#include "Animal.h"
using namespace std;

class Reptile: public Animal{
    private:
        string bloodType;
        string skinType;

    public:
        Reptile(string, int, char, string, string);
        friend ostream &operator<<(ostream &os, const Reptile &r);

        string getBloodType();
        string getSkinType();
};

#endif //LAB9_REPTILE_H