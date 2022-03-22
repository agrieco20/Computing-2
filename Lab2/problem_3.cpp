/*************************
 * Filename: problem_3.cpp
 * Author: Anthony Grieco
 * Description: This program will take values (given by the user) related to their gross pay per week.
 *              The program will then return the values they inputted (Pay rate, Hours worked) and calculates
 *              how much money they earned that week (over 40 hours of work yields an overtime pay of 1.5 the
 *              normal rate).
 ***********************/

#include <iostream>
#include <string>

using namespace  std;

int main() {
    string userName;
    float userStandardPayRate, userTotalHoursWorked, calculatedGrossPay, OverTimeHours;

    cout << "What is your name?" << endl;
    getline(cin, userName);

    cout << "How many total hours did you work this week?" << endl;
    cin >> userTotalHoursWorked;

    cout << "What is your standard rate of pay?" << endl;
    cin >> userStandardPayRate;

    cout << fixed;
    cout.precision(3);

    //Time and a Half Pay
    if(userTotalHoursWorked > 40.00){
        OverTimeHours = userTotalHoursWorked - 40.00;

        calculatedGrossPay = ((userTotalHoursWorked - OverTimeHours) * userStandardPayRate) + (OverTimeHours * userStandardPayRate * 1.50);
    }

    //Regular Pay
    else{
        calculatedGrossPay = userStandardPayRate * userTotalHoursWorked;
    }

    cout.precision(2);
    cout <<  userName << "'s Pay Stub" << endl;
    cout << "\t Rate: " << userStandardPayRate << endl;
    cout << "\t Hours Worked: " << userTotalHoursWorked << endl;
    cout << "\t Total Gross Pay: $" << calculatedGrossPay << endl;

    return 0;
}