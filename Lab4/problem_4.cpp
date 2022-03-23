/*****
 * Filename: problem_4.cpp
 * Author: Anthony Grieco
 * Description: This program provides the following analysis on the grades: Display the number of
 *      grades in the vector, the highest grade, the lowest grade, the mean of all of the grades and the
 *      standard deviation(all to two decimal places).
 */

#include <iostream>
#include "grades.h"
#include <cmath>

using namespace std;

vector<double> myGrades(getGrades());

int main() {
    int totalNumGrades;
    double maxGrade, minGrade, meanGrade, variance, stdDevGrade;

    totalNumGrades = myGrades.size();

    //Finds the Highest Grade (maxGrade) and the Lowest Grade (minGrade)
    //Adds all of the elements to the meanGrades variable so it can be divided by the total number of elements later on
    for (int i = 0; i < myGrades.size(); i++){

        meanGrade += myGrades[i];

        if (i == 0){ //Base Case
            maxGrade = myGrades[0];
            minGrade = myGrades[0];
        }

        else{
            maxGrade = max(maxGrade, myGrades[i]);
            minGrade = min(minGrade, myGrades[i]);
        }
    }

    meanGrade /= myGrades.size(); //Divides the sum of all the grades by the total number of elements in order to find the mean.

    //Calculates the variance between each of the elements in myGrades
    for (int i = 0; i < myGrades.size(); i++){
        variance += pow(myGrades[i] - meanGrade,2);
    }

    variance /= myGrades.size(); //Divides the variance by the total number of elements in myGrades to find the average variance
    stdDevGrade = sqrt(variance); //calculates the standard deviation by using the square root of the average variance

    cout << fixed;
    cout.precision(2);

    cout << "Number of Elements in Grades: " << totalNumGrades << endl;
    cout << "Highest Score: " << maxGrade << endl;
    cout << "Lowest Score: " << minGrade << endl;
    cout << "Mean of the Scores: " << meanGrade << endl;
    cout << "The standard deviation of the scores: " << stdDevGrade << endl;

    return 0;
}