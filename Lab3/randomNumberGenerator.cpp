//
// Created by Anthony Grieco on 2/23/2021.
//

#include <iostream>
#include <ctime>
#include <random>

using namespace std;

int randNumGen(bool shooterAssign){
    int dice1_Roll, dice2_Roll, diceRollTotal;

    static default_random_engine rand(time(0));
    uniform_int_distribution <int>randDistro(1,6);

    if (shooterAssign == false) {
        dice1_Roll = randDistro(rand);
        return dice1_Roll;
    }

    else{
        dice1_Roll = randDistro(rand);
        dice2_Roll = randDistro(rand);

        diceRollTotal = dice1_Roll + dice2_Roll;
        return diceRollTotal;
    }
}