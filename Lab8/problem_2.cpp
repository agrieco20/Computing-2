/**
 * Filename: problem_2.cpp
 * Author: Anthony Grieco
 * Description: Create the Datetime2class with each of the methods in the UML diagram. The class contains a
 *      subclass in the form of struct datetime named dt.  The struct will hold the requested date time
 *      information upon instantiation.  This data will not change unless the update() method is evoked.
 *      As we are now storing the date time information for the user of our class, we have renamed our methods
 *      that still supply realtime date and time capability but the requirements are the same as problem 1.
 *      Additionally, you will implement the operator overloaded method for ++, --both pre increment and post
 *      increment.  You will also implement the overloaded operator + and -. Each of these operators will
 *      only act on the stored year information in the dt struct.  Write a program that tests each of the
 *      methods in your class including the update method. This will bea useful class for you.
 */

#include <iostream>
#include <unistd.h> //Used to create a pause lasting 5 seconds in the program to test the "update" method
#include "Datetime2.cpp"

using namespace std;

int main() {

    Datetime2 myDatetime2; //Creates a Datetime2 object

    //Testing each method (below):
    cout << "Current Time (12 Hour Clock):" << myDatetime2.getCurTimeStr() << endl;
    cout << "Current Time (24 Hour Clock):" << myDatetime2.getTimeStr24() << endl;
    cout << "Current Date:" << myDatetime2.getCurDateStr() << endl;
    cout << "Current Day:" << myDatetime2.c_day() << endl;
    cout << "Current Month:" << myDatetime2.c_month() << endl;
    cout << "Current Year:" << myDatetime2.c_year() << endl;
    cout << "Current Hour Description (a.m. or p.m.):" << myDatetime2.c_hour() << endl;
    cout << "Current Hour:" << myDatetime2.c_hour24() << endl;
    cout << "Current Minute:" << myDatetime2.c_min() << endl;
    cout << "Current Second:" << myDatetime2.c_sec() << endl;

    cout << "----------------------------------------------" << endl;

    myDatetime2.update();

    cout << "* The Program will now be Paused for 5 Seconds to Test the 'update' Method *" << endl;
    sleep(5); //Pauses the program for 5 seconds (uses <unistd.h> library)

    //Tests the updated values (below):
    cout << "The Updated Year is: " << myDatetime2.c_year() << endl;
    cout << "The Updated Month is: " << myDatetime2.c_month() << endl;
    cout << "The Updated Day is: " << myDatetime2.c_day() << endl;
    cout << "The Updated Hour is: " << myDatetime2.c_hour24() << endl;
    cout << "The Updated Minute is: " << myDatetime2.c_min() << endl;
    cout << "The Updated Second is: " << myDatetime2.c_sec() << endl;

    cout << "----------------------------------------------" << endl;

    cout << "The following statements use overloaded operators:" << endl;

    //Tests values altered using overloaded operators:
    myDatetime2++;
    cout << "The Altered Year [Operator: ++] is: " << myDatetime2.datetime.year << endl;
    myDatetime2--;
    cout << "The Altered Year [Operator: --] is: " << myDatetime2.datetime.year << endl;
    ++myDatetime2;
    cout << "The Altered Year [Operator: ++(int)] is: " << myDatetime2.datetime.year << endl;
    --myDatetime2;
    cout << "The Altered Year [Operator: --(int)] is: " << myDatetime2.datetime.year << endl;
    myDatetime2 + 20;
    cout << "The Altered Year [Operator: +] is: " << myDatetime2.datetime.year << endl;
    myDatetime2 - 20;
    cout << "The Altered Year [Operator: -] is: " << myDatetime2.datetime.year << endl;

    return 0;
}