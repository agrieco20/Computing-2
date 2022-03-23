/**
 * Author: Anthony Grieco
 * Filename: problem_4.cpp
 * Description: Write a program that opens and reads the file called grades.txt. This file contains the first
 *      and lastnames of students and their grades on the last 10 assignments.Create a student struct that
 *      will store the firstname, lastname and a vector or array (doubles) of the grades, and the current
 *      average of the grades. Print out the student names and their current average.
 */

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

struct Student {
    string firstName;
    string lastName;
    vector <double> grades;
};

int main() {
    Student myStudent;

    string line;
    string tempNum; //Placeholder to hold string grades before being converted by stod() and sent to convertNum
    double convertNum = 0.0; //Placeholder for converted grade before being send to vector grades
    double averageGrade = 0.0;

    bool firstNameBeingRecorded = true; //Used to determine whether the first name is being recorded
    bool lastNameBeingRecorded = false; //Used to determine whether the last name is being recorded

    vector <Student> studentList;

    string infileName = "Grades.txt";

    ifstream infile;
    infile.open(infileName); //Opens "Grades.txt" to be read

    if (infile.is_open()){
        while (getline (infile, line)) {

            firstNameBeingRecorded = true; //Reset
            lastNameBeingRecorded = false; //Reset

            for (int i = 0; i < line.length(); i++) {

                //Records First Name
                if (firstNameBeingRecorded == true && isalpha(line[i])) {
                    myStudent.firstName += line[i];
                }

                //Records Last Name
                else if (lastNameBeingRecorded == true && isalpha(line[i])) {
                    myStudent.lastName += line[i];
                }

                //Records Grades in a vector
                if (firstNameBeingRecorded == false && lastNameBeingRecorded == false){
                    if (!isalpha(line[i]) && isalnum(line[i]) || ispunct(line[i])){
                        tempNum += line[i];
                    }

                    //If a space or the end of the line is encountered, then a string number is ready to be converted to a double
                    if (isspace(line[i]) || i == line.size()-1) {
                        convertNum = stod(tempNum);

                        tempNum = ""; //Resets tempNum (empties the stored string value)

                        myStudent.grades.push_back(convertNum);
                    }
                }
                //Switches between first name and last name for each student
                if (firstNameBeingRecorded == true && isspace(line[i])) {
                    firstNameBeingRecorded = false;
                    lastNameBeingRecorded = true;
                }

                //Disables the two booleans to allow numbers to be converted into doubles
                else if (lastNameBeingRecorded == true && isspace(line[i])) {
                    firstNameBeingRecorded = false;
                    lastNameBeingRecorded = false;
                }
            }

            studentList.push_back(myStudent);

            //Resets each of the values in the myStudent structure so that a new student can be recorded and later added to the studentList vector
            myStudent.firstName = {};
            myStudent.lastName = {};
            myStudent.grades = {};
        }
    }

    //Iterates through a loop to determine the average grade for each student and prints out their first and last name
    for (int i = 0; i < studentList.size(); i++){

        averageGrade = 0.0; //Resets average

        //Calculates the current average for each student by using all the elements in their grades vector
        for (int j = 0; j < studentList[i].grades.size(); j++){
            averageGrade += studentList[i].grades[j];
        }

        //Divides by the total number of grades to produce the average
        averageGrade /= studentList[i].grades.size();

        cout << fixed;
        cout.precision(2);

        //Prints out all students and their average grade
        cout << studentList[i].firstName << " " << studentList[i].lastName << ": " << averageGrade << endl;
    }

    infile.close(); //Closes "Grades.txt" when finished with program

    return 0;
}