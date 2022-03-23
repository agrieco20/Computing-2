/*****
 * Filename: problem_1.cpp
 * Author: Anthony Grieco
 * Description: This program asks the user for a phrase, and encrypts the phrase using a simple shift algorithm.
 *      Each letter in the message will be replaced with the letter following it in the alphabet.
 *      ‘a’ will be ‘b’, ‘b’ will be ‘c’ etc.  Punctuation will be reproduced without modification.
 *      The user can encrypt as many messages as they want in a session.
 */

#include <iostream>

using namespace std;

int main() {
    string repeatProgram, userInput, reversedOutput;

    do {
        reversedOutput.clear(); //Clears the string output every time the program runs so that previous phrases will not overlap

        cout << "Please enter a phrase to encrypt: ";
        getline(cin, userInput);
        cout << endl;

        for (int i = 0; i<userInput.length(); i++){
            if (ispunct(userInput[i]) || isspace(userInput[i])) { //checks to see if a space or punctuation is used (keeps the space/punctuation if so)
                reversedOutput += userInput[i];
            }

            else { //If the char is not punctuation or a space, then the next letter is printed (ex: 'a' --> 'b')
                reversedOutput += userInput[i]+1;
            }
        }

        cout << "Original String: " << userInput << endl;

        cout << "Shifted String: " <<  reversedOutput << endl;

        cout << "Do you want to encrypt another (Y/N)?";
        getline(cin, repeatProgram);
        cout << endl;

    } while(repeatProgram == "Y" || repeatProgram == "y");

    return 0;
}