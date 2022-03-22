/*************************
 * Filename: problem_5.cpp
 * Author: Anthony Grieco
 * Description: This program will asks the user how many times they want a pair of dice to be rolled.
 *              The program then rolls the two dice that many times and records the outcomes each time.
 *              Finally, the program states how many times the dice rolled doubles.
 ***********************/

#include <iostream>
#include <ctime>
#include <random>

using namespace std;

int main() {
    int userPick_RollNum, dice1_Roll, dice2_Roll, doublesRolledTotal;
    float doublesRolledRate;

    default_random_engine rand(time(0));
    uniform_int_distribution <int>randDistro(1,6);

    cout << "How many times do want to roll the dice? ";
    //cin >> userPick_RollNum;
    //cout << endl;

    bool repeat = false;
    do {
        try {
            //repeat = false;
            cin >> userPick_RollNum;
        }
        catch (int) {
            cout << "success" << userPick_RollNum;
            repeat = false;
        }

        catch (...) {
            cout << "failure";
            repeat = true;
        }
    }while(repeat == true);

    for (int i = 0; i < userPick_RollNum; i++){
        dice1_Roll = randDistro(rand);
        dice2_Roll = randDistro(rand);

        cout << "You rolled: " << dice1_Roll << " " << dice2_Roll << endl;
        if(dice1_Roll == dice2_Roll){
            cout << "\tYou rolled Doubles!" << endl;
            doublesRolledTotal++;
        }
    }

    cout << "You rolled Doubles " << doublesRolledTotal << " times out of " << userPick_RollNum << "." << endl;


    doublesRolledRate = (float)doublesRolledTotal/userPick_RollNum;
    cout << "That's " << doublesRolledRate * 100 << "%" << endl;

    return 0;
}