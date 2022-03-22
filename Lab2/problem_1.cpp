/*************************
 * Filename: problem_1.cpp
 * Author: Anthony Grieco
 * Description: This program will determine if a number given by the user is odd or even.
 ***********************/

#include <iostream>

using namespace std;

int main() {

    int userInput_Integer;

    cout << "Please enter a whole number: " << endl;
    cin >> userInput_Integer;

    if (userInput_Integer % 2 == 1) {
        cout << "Odd" << endl;
    }
    else{
        cout << "Even" << endl;
    }

    return 0;
}