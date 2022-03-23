/**
 * Author: Anthony Grieco
 * Filename: problem_5.cpp
 * Description: Write a program that uses the provided RomeoAndJuliet.txt. Read the file and analyze the text,
 *      printing out nicely formatted statistics on the console. Report on the following: Total words in the
 *      text. Total letters in the text not including punctuation and spaces. On what line does the text
 *      “star-crossed lovers” appear? What is the average word length in the text?What is the longest word
 *      in the text?
 */

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main() {

    string stringOfWords;
    vector <string> sentence;

    string infileName = "RomeoAndJuliet.txt";
    ifstream infile;
    infile.open(infileName); //Opens "RomeoAndJuliet.txt" to be read



    int totalWords = 0, totalLetters = 0, starCrossedLoversLine = 0, longestWordLetterCount = 0, longestWordLetterChecker = 0;
    double avgWordLength = 0.0;
    string currentWord, longestWord;

    if (infile.is_open()){ //Created a new vector to store the stringOfWords variable from the imported text
        while(getline(infile, stringOfWords)){
            sentence.push_back(stringOfWords);
        }
    }

    for (string line: sentence){
        for (int i = 0; i < line.size(); i++){

            //Word Count:
            if (isalpha(line[i-1]) && ispunct(line[i]) || isalpha(line[i-1]) && isspace(line[i]) || isalpha(line[i]) && i==line.size()-1){
                totalWords++;
            }

            //Letter Count:
            if (isalpha(line[i])){
                totalLetters++;
                longestWordLetterChecker++; //Used to help determine longest word (acts as a temporary value to store how many letters the current word has)
                currentWord += line[i]; //Used to determine longest word (acts as a temporary storage place for the current word being checked)
            }

            //Determining Longest Word:

            //Checks to see if there is punctuation, a space, or the end of a line (these conditions indicate the end of a word)
            if (ispunct(line[i]) || isspace(line[i]) || i == line.size()-1) {

                //Checks to see if there is a new longest word (saves it if there is)
                if (longestWordLetterChecker > longestWordLetterCount) {
                    longestWordLetterCount = longestWordLetterChecker;
                    longestWord = currentWord;
                }

                longestWordLetterChecker = 0; //Resets the letter count to 0 after checking a word
                currentWord.clear(); //Resets (empties) the string so that a new word can be checked
            }
        }
    }

    //Checking for Line that "star-crossed lovers" is On
    for (int i = 0; i < sentence.size(); i++){

        //Looks for the string "star-crossed lovers". If it is found, the program will spit out the line it is found on (otherwise it returns "0")
        if (sentence[i].find("star-crossed lovers") < sentence[i].size()) {

            starCrossedLoversLine = i + 1; //Adds 1 so that the line can be identified by the user in normal English (not via computing logic)
        }
    }

    //Average letters Per Word:
    avgWordLength = (double) totalLetters/totalWords;

    cout<<fixed;
    cout.precision(2);

    //Output:
    cout << "Total words in the given text: " << totalWords << endl;
    cout << "Total letters in the given text (not including punctuation and spaces): " << totalLetters << endl;
    cout << "Line the text 'star-crossed lovers' appears on: " << starCrossedLoversLine << endl;
    cout << "Average word length in the text: " << avgWordLength << " Letters a Word" << endl;
    cout << "Longest word in the text: " << longestWord << endl;


    infile.close(); //Closes "RomeoAndJuliet.txt" when finished with program
    return 0;
}