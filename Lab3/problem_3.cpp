/************************
 * Filename: problem_3.cpp
 * Author: Anthony Grieco
 * Description: This program runs a Simple Craps Dice Game that allows 2 players to bet against one another.
 *      Players enter their names and the amount of money they will put in as the price of entry to the game.
 *      A minimum entry fee of $100.00 is required to play although players may pay more. Once their entry fee is
 *      paid, they cannot change it for the duration of the game–we’ll call this money that players bank. A single
 *      die is rolled by the computer to start the game: if the roll is a 1,2 or 3 player One goes first.
 *      If the roll is a 4,5 or 6 player Two goes first. Whoever goes first is called the shooter. Both players
 *      place their bet on whether the shooter will win, the bet must not exceed their bank and bets are limited to
 *      amounts between $0 and $25. After both players bet, the shooter rolls 2 die.  The shooter wins if they roll
 *      2, 3, 4, 10, 11 or 12. The shooter loses if they throw 5, 6, 7, 8 or 9.The house (the computer) either pays
 *      to each player’s bank if the shooter won, or debits each player’s bank if the shooter lost. Player two now
 *      becomes the shooter and game play continues switching back and forth between players being the shooter.
 *      Game play continues until one player resigns or runs out of money. At the conclusion of the game the program
 *      displays the results for each player (# of wins, #of loses and amount in their bank to be paid out).
***********************/

#include <iostream>
#include "randomNumberGenerator.h"
#include <string>

using namespace std;

int main(){
    double p1_Bank = 0.0, p2_Bank = 0.0, p1_Bet = 0.0, p2_Bet = 0.0;
    bool shooterAssign = false, p1_Shooter = false, p2_Shooter = false;
    string p1_Name, p2_Name, continuePlaying;
    int shooterDiceValue = 0, p1_WinCount = 0, p2_WinCount = 0, p1_LossCount = 0, p2_LossCount = 0, turnCount = 0;

    cout << "Welcome to the game of Craps. Player 1, what is your name? ";
    getline(cin, p1_Name);
    cout << endl;

    cout << "Player 2, what is your name? ";
    getline(cin, p2_Name);
    cout << endl;

    cout<<"In order to play this game, each player must put at least $100 into their bank.\n" << p1_Name <<", please place your desired about of money (in dollars) into your bank: $";
    cin >> p1_Bank;
    cout << endl;

    do {
        if(p1_Bank < 100){
            cout << "You must place at least $100 into the bank. \nPlease place your desired about of money (in dollars) into your bank " << p1_Name << ": $";
            cin >> p1_Bank;
            cout << endl;
        }
    } while(p1_Bank < 100);

    cout << p2_Name << ", please place your desired about of money (in dollars) into your bank: $";
    cin >> p2_Bank;
    cout << endl;

    do {
        if(p2_Bank < 100){
            cout << "You must place at least $100 into the bank. \nPlease place your desired about of money (in dollars) into your bank " << p2_Name << ": $";
            cin >> p2_Bank;
            cout << endl;
        }
    } while(p2_Bank < 100);

    cout << "To determine who goes first, a dice will be rolled. \nIf the dice lands on a 1, 2, or 3, " << p1_Name << " will go first. \nIf it is a 4, 5, or 6, " << p2_Name << " will go first." << endl;
    shooterDiceValue = randNumGen(shooterAssign); //The shooter has not been assigned yet, so only one dice will be used to determine who starts
    if(shooterAssign == false) {
        if (shooterDiceValue >= 1 && shooterDiceValue <= 3) {
            p1_Shooter = true;
            cout << "The dice landed on a " << shooterDiceValue << " meaning " << p1_Name << " is the shooter and goes first!" << endl;
        }
        else {
            p2_Shooter = true;
            cout << "The dice landed on a " << shooterDiceValue << " meaning " << p2_Name << " is the shooter and goes first!" << endl;
        }
        shooterAssign = true;
    }

    if (shooterAssign == true){ //Once the shooter has been assigned, the game will begin (will use 2 dice from now on)
        cout << "In this game, you are making bets based on the sum of two dice. "
                "\nIf the shooter rolls a 2, 3, 4, 10, 11, or 12, then both players receive the amount of money they bet. "
                "\nIf the shooter rolls anything else, both players lose the money they bet."
                "\nIf you lose all of the money that was in your bank, the game is over and the other player wins. "
                "\nPlayers can bet between $0 and $25" << endl;

        //The game is over once either player has gone bankrupt
        do{
              if (p1_Shooter == true){
                  turnCount++;
                  cout << p1_Name << ", it is your turn to be the shooter. How much money do you want to bet? $";
                  cin >> p1_Bet;
                  cout << endl;

                  do{
                      if(p1_Bet < 0 || p1_Bet > 25){
                          cout << "Your bet must be a positive value and no greater than $25. How much money do you want to bet " << p1_Name <<"? $";
                          cin >> p1_Bet;
                          cout << endl;
                      }

                  }while(p1_Bet < 0 || p1_Bet > 25);

                  do {
                      if (p1_Bet > p1_Bank){
                          cout << "You can't bet money that you don't have! You can bet a maximum of $" << p1_Bank << ".\nWhat is your bet? ";
                          cin >> p1_Bet;
                          cout << endl;
                      }
                  } while(p1_Bet > p1_Bank);

                  cout << p2_Name << ", how much money do you want to bet? $";
                  cin >> p2_Bet;
                  cout << endl;

                  do{
                      if(p2_Bet < 0 || p2_Bet > 25){
                          cout << "Your bet must be a positive value and no greater than $25. How much money do you want to bet " << p2_Name <<"? $";
                          cin >> p2_Bet;
                          cout << endl;
                      }
                  }while(p2_Bet < 0 || p2_Bet > 25);

                  do{
                      if (p2_Bet > p2_Bank){
                          cout << "You can't bet money that you don't have! You can bet a maximum of $" << p2_Bank << ".\nWhat is your bet? ";
                          cin >> p2_Bet;
                          cout << endl;
                      }
                  }while(p2_Bet > p2_Bank);

                  shooterDiceValue = randNumGen(shooterAssign);
                  if (shooterDiceValue >= 2 && shooterDiceValue <= 4 || shooterDiceValue >= 10 && shooterDiceValue <= 12){
                      cout << "Congrats! " << p1_Name << " rolled a " << shooterDiceValue << ".\nYour bets have been added to your individual balances." << endl;
                      p1_Bank += p1_Bet;
                      p2_Bank += p2_Bet;

                      p1_WinCount++;
                  }

                  else {
                      cout << "Unfortunately, " << p1_Name << " rolled a " << shooterDiceValue << ".\nYour bets have been taken from your individual balances." << endl;
                      p1_Bank -= p1_Bet;
                      p2_Bank -= p2_Bet;

                      p1_LossCount++;
                  }

                  cout << "Current Totals:\n"<<p1_Name<<": $" << p1_Bank << "\n" << p2_Name << ": $" << p2_Bank << endl;

                  p1_Shooter = false;
                  p2_Shooter = true;

              }

              if (p2_Shooter == true){
                  turnCount++;
                  cout << p2_Name << ", it is your turn to be the shooter. How much money do you want to bet? $";
                  cin >> p2_Bet;
                  cout << endl;

                do{
                    if(p2_Bet < 0 || p2_Bet > 25){
                        cout << "Your bet must be a positive value and no greater than $25. How much money do you want to bet " << p2_Name <<"? $";
                        cin >> p2_Bet;
                        cout << endl;
                    }
                }while(p2_Bet < 0 || p2_Bet > 25);

                do{
                    if (p2_Bet > p2_Bank){
                        cout << "You can't bet money that you don't have! You can bet a maximum of $" << p2_Bank << ".\nWhat is your bet? ";
                        cin >> p2_Bet;
                        cout << endl;
                    }
                } while(p2_Bet > p2_Bank);

                cout << p1_Name << ", how much money do you want to bet? $";
                cin >> p1_Bet;
                cout << endl;

                do{
                    if(p1_Bet < 0 || p1_Bet > 25){
                        cout << "Your bet must be a positive value and no greater than $25. How much money do you want to bet " << p1_Name <<"? $";
                        cin >> p1_Bet;
                        cout << endl;
                    }
                }while(p1_Bet < 0 || p1_Bet > 25);

                do {
                    if (p1_Bet > p1_Bank){
                        cout << "You can't bet money that you don't have! You can bet a maximum of $" << p1_Bank << ".\nWhat is your bet? ";
                        cin >> p1_Bet;
                        cout << endl;
                    }
                } while(p1_Bet > p1_Bank);

                shooterDiceValue = randNumGen(shooterAssign);
                if (shooterDiceValue >= 2 && shooterDiceValue <= 4 || shooterDiceValue >= 10 && shooterDiceValue <= 12){
                    cout << "Congrats! " << p2_Name << " rolled a " << shooterDiceValue << ".\nYour bets have been added to your individual balances." << endl;
                    p1_Bank += p1_Bet;
                    p2_Bank += p2_Bet;

                    p2_WinCount++;
                }

                else {
                    cout << "Unfortunately, " << p2_Name << " rolled a " << shooterDiceValue << ".\nYour bets have been taken from your individual balances." << endl;
                    p1_Bank -= p1_Bet;
                    p2_Bank -= p2_Bet;

                    p2_LossCount++;
                }

                cout << "Current Totals:\n"<<p1_Name<<": $" << p1_Bank << "\n" << p2_Name << ": $" << p2_Bank << endl;

                p1_Shooter = true;
                p2_Shooter = false;
            }

              if (turnCount % 2 == 0) {
                  cout << "Would you like to continue playing? ('Yes' or 'No') ";
                  cin >> continuePlaying;
                  cout << endl;
              }
        } while(p1_Bank > 0 && p2_Bank > 0 && continuePlaying == "Yes" || p1_Bank > 0 && p2_Bank > 0 && continuePlaying == "yes");

        //Final stats are shown and the game ends
        cout << "\nGame Over! Here are your stats: \nPlayer: \t\t" << p1_Name << "\t\t" << p2_Name << "\nShooter Wins: \t\t" << p1_WinCount << "\t\t" << p2_WinCount << "\nShooter Losses: \t" << p1_LossCount << "\t\t" << p2_LossCount << "\nRemaining Balance: \t$" << p1_Bank  << "\t\t$" << p2_Bank;
    }
    return 0;
}