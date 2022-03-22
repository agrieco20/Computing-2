/*************************
 * Filename: problem_4.cpp
 * Author: Anthony Grieco
 * Description: This program will asks for a user's height and weight and then determines their
 *              Body Mass Index (BMI). The program then determines if their BMI is within the healthy
 *              range (19.0 through 25.0) for their given height and weight.
 ***********************/

#include <iostream>

using namespace std;

void calcBMI(float, float);

int main() {

    float userWeight, userHeight;

    cout << "Enter Weight [lbs.]:\t";
    cin >> userWeight;
    cout << endl;

    cout <<  "Enter Height [in]:\t";
    cin >> userHeight;
    cout << endl;

    calcBMI(userHeight, userWeight);

    return 0;
}

void calcBMI(float height, float weight){

    cout<<fixed;
    cout.precision(2);

    float BMI_Calculator = (weight * 720) / (height * height);

    if (BMI_Calculator >= 19.0 && BMI_Calculator <= 25.0){
        cout << BMI_Calculator << " BMI is within the healthy range.";
    }

    else if (BMI_Calculator > 25.0){
        cout << BMI_Calculator << " BMI is above the healthy range.";
    }

    else if (BMI_Calculator < 19.0){
        cout << BMI_Calculator << " BMI is below the healthy range.";
    }
}