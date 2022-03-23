/**
 * Filename: Fish.h
 * Author: Anthony Grieco
 * Description: Creates the declaration for the fish class
 */

#ifndef LAB9_FISH_H
#define LAB9_FISH_H

#include "Animal.h"
using namespace std;

class Fish: public Animal{
    private:
        int finNum;
        int gillNum;

    public:
        Fish(string, int, char, int, int);
        friend ostream &operator<<(ostream &os, const Fish &f);

        int getFinNum();
        int getGillNum();
};

#endif //LAB9_FISH_H