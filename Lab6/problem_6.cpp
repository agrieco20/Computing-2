/**
 * Author: Anthony Grieco
 * Filename: problem_1.cpp
 * Description: Write a program that extends problem 2, instead of printing the names and information entered
 *      on the console, write the information to a file named “students.txt”.
 */

#include <iostream>
#include <fstream>
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

    string outFileName = "students.txt";
    ofstream outfile;
    //outfile.open(outFileName, ios::app); //Would be used to continuously add data (not necessary here because the code just needs to print out the current information - not from every time the program is run)
    outfile.open(outFileName);

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

        //Prints everything to a file named "students.txt"
        for (int i = 0; i < studentList.size(); i++) {
            outfile << studentList[i].firstName << ", " << studentList[i].lastName << ", " << studentList[i].age << ", " << studentList[i].gpa << endl;
        }

    outfile.close();
    return 0;
}