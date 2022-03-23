/**
 * Author: Anthony Grieco
 * Filename: problem_2.cpp
 * Description: Write a program that asks the user to enter student data, to include: firstname, lastname, age,
 *      and GPA. (string, string, integer, double). The user can enter as many students as the would like.
 *      Write your own definition of a student struct that contains the above attributes and use it two
 *      capture the data the user entered. Use some container structure, array or vector, to hold all the
 *      student structs. Print out all the data the user entered when they are done entering students.
 */

#include <iostream>
#include <vector>

using namespace std;

struct Student{
    string firstName;
    string lastName;
    int age;
    double gpa;
};

int main() {

    Student myStudent;
    string repeatProgram;
    vector <Student> studentList;

    do {
        repeatProgram.clear();
        myStudent.firstName = {};
        myStudent.lastName = {};
        myStudent.age = {};
        myStudent.gpa = {};

        cout << "Enter First Name:";
        getline(cin, myStudent.firstName);
        cin.clear();
        fflush(stdin);

        cout << "Enter Last Name:";
        getline(cin, myStudent.lastName);
        cin.clear();
        fflush(stdin);

        cout << "Enter Age:";
        cin >> myStudent.age;
        cin.clear();
        fflush(stdin);

        cout << "Enter GPA:";
        cin >> myStudent.gpa;
        cin.clear();
        fflush(stdin);

        studentList.push_back(myStudent);

        cout << "Enter another student (Y/N)?";
        getline(cin, repeatProgram);
        cin.clear();
        fflush(stdin);

    } while (repeatProgram == "Y" || repeatProgram == "y");
    cout << endl;

    for (int i = 0; i < studentList.size(); i++){
        cout << studentList[i].firstName << ", " << studentList[i].lastName << ", " << studentList[i].age << ", " << studentList[i].gpa << endl;
    }

    return 0;
}