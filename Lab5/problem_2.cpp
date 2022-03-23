/**
 * Filename: problem_2.cpp
 * Author: Anthony Grieco
 * Description: This program asks the user whether they want to enter either an integer, a double precision
 *      floating point number, a single character or a string. Once they have indicated what type they want to
 *      enter, ask them to enter the value. Calling a single function name in your main program named print,
 *      print out the value that the user entered. Your overloaded function will return void, will accept only
 *      one argument and must be named print.
 */

#include <iostream>
#include <string>

using namespace std;

void print(int);
void print(double);
void print(char);
void print(string);

int main() {
    int userChoice, i_userInput;
    double db_userInput;
    char cr_userInput;
    string str_userInput;

    do {
        cout << "Which of the following would you like to enter?"
                "\n1. Integer \t\t2. Double Precision Floating Point Number\n3. Single Character \t4. String"
                "\nPlease type the number corresponding to your choice: ";
        cin >> userChoice;
        cout << endl;

    } while(userChoice < 0 || userChoice > 5);

    switch(userChoice){
        case 1: //Int
            cout << "What would you like to have printed?";
            cin >> i_userInput;

            print(i_userInput);
            break;

        case 2: //Double
            cout << "What would you like to have printed?";
            cin >> db_userInput;

            print(db_userInput);
            break;

        case 3: //Char
            cout << "What would you like to have printed?";
            cin >> cr_userInput;

            print(cr_userInput);
            break;

        case 4: //String
            cout << "What would you like to have printed? ";
            cin.ignore();
            getline(cin,str_userInput);

            print(str_userInput);
            break;
    }
    return 0;
}

void print(int userInput){
    cout << userInput << endl;
}

void print(double userInput){
    cout << userInput << endl;
}

void print(char userInput){
    cout << userInput << endl;
}

void print(string userInput){
    cout << userInput << endl;
}