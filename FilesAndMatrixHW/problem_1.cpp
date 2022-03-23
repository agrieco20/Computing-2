/**
 * Filename: problem_1
 * Author: Anthony Grieco
 * Description: Opens the file 'BBSongsOneByWeek-2020.csv' and allows the user to search the file by inputting
 *      a value for the week they want to search. The file pointer is reset after and asks the user if they want
 *      to look at another week. The file doesn't close until the user is finished with the program.
 */

#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

int main() {
    string line; //Used to extract each line from file
    string convertedLine; //Used to remove commas and add in spacing for when the desired line referring to the week requested by the user is sent to it
    char repeatProgram; //Used to determine if a user wanted to look at data from another week
    int weekNeeded; //User Input for which week's data they want to see
    int linePlacement; //Used to calculate the start of the line (for the file pointer) that has been requested by the user

    string inFileName = "BBSongsOneByWeek-2020.csv";
    ifstream infile;
    infile.open(inFileName, ios::in);

    do {
        infile.seekg(ios::beg); //Resets file pointer
        cout << "Which week's data would you like to look at?";
        cin >> weekNeeded;

        do {
            if(weekNeeded < 1 || weekNeeded > 52){ //Checks for valid input
                cin.clear();
                weekNeeded = 0;
                cout << endl;

                cout << "There are only 52 weeks in a year. Please input a value between 1 and 52:";
                cin >> weekNeeded;
            }
        } while(weekNeeded < 1 || weekNeeded > 52);

        cout << endl;

        for(int i = 0; i < weekNeeded +1; i++){ //Adds the size of each line to 'linePlacement'
            getline(infile,line);
            linePlacement += line.size();
        }

        infile.seekg(linePlacement);

        convertedLine = line;

        for (int i = 0; i<convertedLine.length(); i++){ //Prints out the desired line corresponding the the requested week (with proper spacing and no commas)
            if (convertedLine[i] == ','){
                convertedLine[i] = ' ';
                cout << setw(5);
            }
            cout << convertedLine[i];
        }

        cout << endl << endl;

        cout << "Would you like to look at data from another week? (Y/N)";
        cin >> repeatProgram;
    } while (repeatProgram == 'Y' || repeatProgram == 'y');

    infile.close();
    return 0;
}