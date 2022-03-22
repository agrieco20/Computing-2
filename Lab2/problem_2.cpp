/*************************
 * Filename: problem_2.cpp
 * Author: Anthony Grieco
 * Description: This program will convert a number (given by the user) from Celsius to Fahrenheit.
 ***********************/

#include <iostream>

using namespace std;

int main() {

    float userInput_Celsius, fahrenheitConversion;

    cout.precision(1);
    cout << fixed;

    cout << "Enter a Celsius temperature for me to convert to Fahrenheit: " << endl;
    cin >> userInput_Celsius;

    fahrenheitConversion = (9.0 / 5.0) * (userInput_Celsius) + 32;

    cout << "Fahrenheit is: " << fahrenheitConversion << endl;

    if (fahrenheitConversion >= 80) {
        cout << fahrenheitConversion << " Degrees F - that's hot!" << endl;
    }

    else if (fahrenheitConversion <= 32) {
        cout << fahrenheitConversion << " Degrees F - that's cold!" << endl;
    }

    return 0;
}