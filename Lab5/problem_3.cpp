/**
 * Filename: problem_3.cpp
 * Author: Anthony Grieco
 * Description: This program asks the user to enter 4 integers. Each integer must have its own variable.
 *      It uses a function that will change the value of the variable by squaring the value. This function
 *      accepts 4 arguments and returns nothing (a void function). It prints out the values of the 4 variables
 *      in main. (You may use pointers or reference variables for this exercise).
 */

#include <iostream>
#include <cmath>

using namespace std;

void valueChange(int *, int *, int *, int *); //Pointers

void valueRef(int &, int &, int &, int &); //Reference Variables

int main() {
    int num1 = 0, num2 = 0, num3 = 0, num4 = 0;

    cout << "Please input Integer #1: ";
    cin >> num1;
    cout << endl;

    cout << "Please input Integer #2: ";
    cin >> num2;
    cout << endl;

    cout << "Please input Integer #3: ";
    cin >> num3;
    cout << endl;

    cout << "Please input Integer #4: ";
    cin >> num4;
    cout << endl;

    valueChange(&num1, &num2, &num3, &num4); //Pointers
    //valueRef(num1, num2, num3, num4); //Reference Variables

    cout << "Integer 1 Squared: " << num1 << endl;
    cout << "Integer 2 Squared: " << num2 << endl;
    cout << "Integer 3 Squared: " << num3 << endl;
    cout << "Integer 4 Squared: " << num4 << endl;

    return 0;
}

void valueChange(int * num1, int * num2, int * num3, int * num4){ //Pointers
    *num1 = pow(*num1,2);
    *num2 = pow(*num2,2);
    *num3 = pow(*num3,2);
    *num4 = pow(*num4,2);
}

void valueRef(int &num1, int &num2, int &num3, int &num4){ //Reference Variables
    num1 = pow(num1,2);
    num2 = pow(num2,2);
    num3 = pow(num3,2);
    num4 = pow(num4,2);
}