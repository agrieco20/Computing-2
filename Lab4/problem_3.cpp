/*****
 * Filename: problem_3.cpp
 * Author: Anthony Grieco
 * Description: This program asks the user for a string and prints out to the screen the same string in reverse.
 *      It will use a recursive function to accomplish this task.
 */

#include <iostream>

using namespace std;

void reverseString(string, int);

int main() {

    string userInput;
    string repeatProgram;
    int numStringLeft;

    do {
        cout << "Enter a string to be reversed: ";
        getline(cin, userInput);
        cout<< endl;

        numStringLeft = userInput.length()-1;
        reverseString(userInput, numStringLeft);

        cout << endl;

        cout << "Do want to do another one? (Y/N): ";
        getline(cin, repeatProgram);
        cout<< endl;

    } while(repeatProgram == "Y" || repeatProgram == "y");

    cout << "Thanks for using this program!";

    return 0;
}

void reverseString(string stringInput, int numLeft){
    if (numLeft < 0){
        return;
    }

    else{
        cout << stringInput[numLeft];
        reverseString(stringInput,numLeft-1);
    }
}