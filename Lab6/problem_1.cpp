/**
 * Author: Anthony Grieco
 * Filename: problem_1.cpp
 * Description: Write a program that asks the user to enter student data, to include: firstname, lastname, age,
 *      and GPA. (string, string, integer, double). Write your own definition of a student struct that contains
 *      the above attributes and use it two capture the data the user entered. Print out all the data the user
 *      entered by accessing the attributes of the struct.
 */

#include <iostream>

using namespace std;

struct Student{
    string firstName;
    string lastName;
    int age;
    double gpa;
};

int main() {

    Student myStudent;

    cout << "Enter First Name:";
    getline(cin, myStudent.firstName);
    cout << endl;

    cout << "Enter Last Name:";
    getline(cin, myStudent.lastName);
    cout << endl;

    cout << "Enter Age:";
    cin >> myStudent.age;
    cout << endl;

    cout << "Enter GPA:";
    cin >> myStudent.gpa;
    cout << endl;

    cout << myStudent.firstName << ", " << myStudent.lastName << ", " << myStudent.age << ", " << myStudent.gpa;

    return 0;
}