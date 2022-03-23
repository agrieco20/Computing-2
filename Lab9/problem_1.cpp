/**
 * Filename: problem_1.cpp
 * Author: Anthony Grieco
 * Description: Tests the methods of the Animal class and prints the results to the console
 */

#include <iostream>
#include "Animal.h"

using namespace std;

int main() {
    Animal animal("Animal", 1, 'M');

    int userInput;

    cout << "The original ID was " << animal.getID() << "." << endl;

    cout << "Please input a new ID:";
    cin >> userInput;
    cout << endl;

    animal.setID(userInput);

    cout << "The name of the animal is: " << animal.name << endl;
    cout << "The gender of the animal is: " << animal.gender << endl;
    cout << "The new ID of the animal is: " << animal.getID() << endl;
    cout << "The phylum of the animal is: " << animal.getPhylum() << endl;

    return 0;
}