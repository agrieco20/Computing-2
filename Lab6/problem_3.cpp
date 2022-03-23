/**
 * Author: Anthony Grieco
 * Filename: problem_3.cpp
 * Description: Write a program that opens and reads the file called grades.txt. This file contains the first
 *      and lastnames of students and their grades on the last 10 assignments.Read the file and print the file
 *      out on the console.
 */

#include <iostream>
#include <fstream>

using namespace std;

int main() {
    string line;
    string infileName = "Grades.txt";

    ifstream infile;
    infile.open(infileName);

    if (infile.is_open()){
        while (getline(infile, line)){
            cout << line << endl;
        }
    }

    infile.close();

    return 0;
}
