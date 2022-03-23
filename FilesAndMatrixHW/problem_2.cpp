/**
 * Filename: problem_2
 * Author: Anthony Grieco
 * Description: The program creates a multidimensional array using the data stored in 'BBSongsOneByWeek-2020.csv'.
 *      The program then asks the user to input the name of an artist and spits back the all the week numbers
 *      the artist was number one. The program allows the user to search for as many artists as they wish.
 */

#include <iostream>
#include <fstream>

using namespace std;

int main() {
    string line; //Used to extract each line from file
    string tempWord; //Used to temporarily add characters so they could be added to the 2D Array later after a comma was used to indicate a new category (exception was the bypass - see below)
    string userInput; //Used by the user to search for an artist in the 2D Array
    int counterX = 0, counterY = 0; //Used to increment the 2D Array when adding tempWord to a new element
    char repeatProgram; //Used to determine whether user wants to look for another artist

    bool quotedName = false; //Used to bypass commas used when listing names (this incident always occurs within quotes [allowing the bypass to occur])
    bool artistFound = false; //Used to determine whether the artist was listed in the 2D Array (if not, activates a statement that says so)

    string weekData[53][6]; //Creates 2D Array

    string inFileName = "BBSongsOneByWeek-2020.csv";
    ifstream infile;
    infile.open(inFileName, ios::in);

    if (infile.is_open()) {
        while (getline(infile, line)) {
            for (int i = 0; i < line.length(); i++){

                if (i == line.length()-1){
                    tempWord += line[i];
                }

                if (line[i]=='"'){
                    if (quotedName == true){
                        quotedName = false;
                    }

                    else{
                        quotedName = true;
                    }
                }

                if (line[i] == ',' && quotedName == false || i == line.length()-1){
                    weekData[counterX][counterY] = tempWord;

                    counterY++;

                    tempWord = ""; //Reset

                    if (counterY == 6) {
                        counterY = 0; //Reset
                        counterX++;
                    }
                }

                else{
                    tempWord += line[i];
                }
            }
        }
    }

    infile.close();

    /*for (int i = 0; i < 53; i++) { //Used to test the elements inside the 2D Array
        for (int j = 0; j < 6; j++) {
            cout << weekData[i][j] << "  ";
            if (j == 5){
                cout << endl << endl;
            }
        }
    } */

    do {
        cin.clear(); //Reset
        cin.sync(); //Reset
        artistFound = false; //Reset

        cout << "What artist would you like to look for?";
        getline(cin, userInput);
        cout << endl;

        for (int i = 1; i < 53; i++) { //Used to test the elements inside the 2D Array
            if (!weekData[i][5].find(userInput)){ //Set to weekData[i][5] because the artist will always be at the 5th index if they were a number 1 artist
              cout << weekData[i][5] << " was the Number 1 Artist in Week " << i << " of 2020." << endl;
              artistFound = true;
            }
        }

        if (artistFound == false){
          cout << "Sorry, " << userInput << " was not a number 1 artist for any week in 2020." << endl;
        }

        cout << "Do you want to search for another artist? (Y/N)";
        cin >> repeatProgram;

    } while(repeatProgram == 'Y' || repeatProgram == 'y');

    return 0;
}