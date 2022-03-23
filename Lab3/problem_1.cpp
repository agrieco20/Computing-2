/************************
 * Filename: problem_1.cpp
 * Author: Anthony Grieco
 * Description: This program will calculate monthly compound interest on an investment. The program will ask
 *      the user for the investment amount, the interest rate, the compounding frequency in months, and the length
 *      in years of that the investment will be accruing interest. The user can use the program as many times as
 *      they want and the final output will be displayed to 2 decimal points.
 ***********************/

#include <iostream>
#include <cmath>

using namespace std;

void compoundInterestCalc(double, double, int, int);

int main() {
    double principalInvestment = 0.0;
    double interestRate = 0.0;
    int numMonthsInterestCompoundedRate = 0;
    int numYearsLoanBorrowed = 0;
    string repeatProgram;

    do {
        cout << "What is your principal investment amount (in dollars)? $";
        cin >> principalInvestment;
        cout << endl;
        do {
            if (principalInvestment < 0){
                cout << "You cannot have a negative principal investment. \nWhat is your principal investment amount (in dollars)? $";
                cin >> principalInvestment;
                cout << endl;
            }
        }while(principalInvestment < 0);

        cout << "What is your annual interest rate? (Please type your percentage as a decimal.)" << endl;
        cin >> interestRate;
        cout << endl;
        do {
            if (interestRate < 0 || interestRate > 1){
                cout << "Please type your annual interest rate as a positive decimal." << endl;
                cin >> interestRate;
                cout << endl;
            }
        } while(interestRate < 0 || interestRate > 1);

        cout << "How many months out of a single year is your interest compounded?" << endl;
        cin >> numMonthsInterestCompoundedRate;
        cout << endl;
        do {
            if (numMonthsInterestCompoundedRate < 1 || numMonthsInterestCompoundedRate > 12) {
                cout << "You must input a value between 1 and 12.\nYour interest must be compounded at least once a year and no more than once a month." << endl;
                cin >> numMonthsInterestCompoundedRate;
                cout << endl;
            }
        } while(numMonthsInterestCompoundedRate < 1 || numMonthsInterestCompoundedRate > 12);

        cout << "How long is your money being invested for (in years)?" << endl;
        cin >> numYearsLoanBorrowed;
        cout << endl;
        do{
            if (numYearsLoanBorrowed < 1){
                cout << "Your loan must last at least one year. Please input an integer that is greater than or equal to 1.";
                cin >> numYearsLoanBorrowed;
                cout << endl;
            }
        }while(numYearsLoanBorrowed < 1);

        compoundInterestCalc(principalInvestment, interestRate, numMonthsInterestCompoundedRate, numYearsLoanBorrowed);
        cout << endl << endl;

        cout << "Would you like to use this compound interest calculator again? (Please answer 'Yes' or 'No'.)" << endl;
        cin >> repeatProgram;
        cout << endl;

    } while (repeatProgram == "Yes" || repeatProgram == "yes");

    return 0;
}

void compoundInterestCalc(double principalInvestment, double interestRate, int numMonthsInterestCompoundedRate, int numYearsLoanBorrowed){
    double totalInvestmentCost;

    totalInvestmentCost = principalInvestment * pow((1 + interestRate/numMonthsInterestCompoundedRate), numMonthsInterestCompoundedRate * numYearsLoanBorrowed);

    cout << fixed;
    cout.precision(2);

    cout << "With a principal investment of $"<< principalInvestment <<", an annual interest rate of " << interestRate << ",\ninterest compounded " << numMonthsInterestCompoundedRate <<" months out of a year and the investment lasting " << numYearsLoanBorrowed <<" years... \nYour total investment would be $" << totalInvestmentCost << ".";
}