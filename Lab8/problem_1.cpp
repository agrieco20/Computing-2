/**
 * Filename: problem_1.cpp
 * Author: Anthony Grieco
 * Description: Create the Datetime class with each of the methods in the UML diagram.  The getDateStr( )
 *      method will provide a string in the form m/d/yyyy ( 04/13/2021).  The hour( )method will provide the
 *      time in a.m. p.m. format as a string.  The hour24()method will provide the numeric hour in 24 hour
 *      format.  The getTimeStr( ) method will provide a string in the form 2:45:23 p.m. and the
 *      getTimeStr24( ) will provide a string in the format 14:45:23.  All the methods will return the
 *      correct data based on the moment the method is invoked. Write a program that will use your class to
 *      test each of your methods and print out the results to the screen. Each method must be tested.
 */

#include <iostream>
#include "Datetime.cpp"

using namespace std;

int main() {

    Datetime myDatetime; //Creates a Datetime object

    //Testing each method (below):
    cout << "Current Time (12 Hour Clock):" << myDatetime.getTimeStr() << endl;
    cout << "Current Time (24 Hour Clock):" << myDatetime.getTimeStr24() << endl;
    cout << "Current Date:" << myDatetime.getDateStr() << endl;
    cout << "Current Day:" << myDatetime.day() << endl;
    cout << "Current Month:" << myDatetime.month() << endl;
    cout << "Current Year:" << myDatetime.year() << endl;
    cout << "Current Hour Description (a.m. or p.m.):" << myDatetime.hour() << endl;
    cout << "Current Hour:" << myDatetime.hour24() << endl;
    cout << "Current Minute:" << myDatetime.min() << endl;
    cout << "Current Second:" << myDatetime.sec() << endl;

    return 0;
}