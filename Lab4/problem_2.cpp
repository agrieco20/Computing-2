/*****
 * Filename: problem_2.cpp
 * Author: Anthony Grieco
 * Description: This program asks the user for a phrase and reports how many vowels (a, e, i,o and u) of each
 *      are in their phrase. It calculates the percentage of the occurrence of each vowel against the total number
 *      of letters in the phrase. It does not count punctuation or spaces in the total letter count.
 */

#include <iostream>
#include <iomanip>
//use the setw() function in this problem to determine the spacing
//Do not include spaces or punctuation in calculations

using namespace std;

int main() {
    string repeatProgram, userInput;

    do{
        int letterCount = 0, a_Count = 0, e_Count = 0, i_Count = 0, o_Count = 0, u_Count = 0;
        double a_Percent = 0, e_Percent = 0, i_Percent = 0, o_Percent = 0, u_Percent = 0;

        cout << "Please enter a phrase for analysis: ";
        getline(cin, userInput);
        cout << endl;

        for (int i =0; i<userInput.length(); i++){
            if (!ispunct(userInput[i]) && !isspace(userInput[i])) {
                letterCount++;
            }

            if (userInput[i] == 'a' || userInput[i] == 'A'){
                a_Count++;
            }

            else if (userInput[i] == 'e' || userInput[i] == 'E'){
                e_Count++;
            }

            else if (userInput[i] == 'i' || userInput[i] == 'I'){
                i_Count++;
            }

            else if (userInput[i] == 'o' || userInput[i] == 'O'){
                o_Count++;
            }

            else if (userInput[i] == 'u' || userInput[i] == 'U'){
                u_Count++;
            }
        }

        a_Percent = (double) a_Count / letterCount *100;
        e_Percent = (double) e_Count / letterCount *100;
        i_Percent = (double) i_Count / letterCount *100;
        o_Percent = (double) o_Count / letterCount *100;
        u_Percent = (double) u_Count / letterCount *100;

        cout << fixed;
        cout.precision(1);

        cout << "Letter" << setw(10) << "Count" << setw(10) << "%" << endl;
        cout << "a:" << setw(10) << a_Count << setw(15) << a_Percent << "%" << endl;
        cout << "e:" << setw(10) << e_Count << setw(15) << e_Percent << "%" << endl;
        cout << "i:" << setw(10) << i_Count << setw(15) << i_Percent << "%" << endl;
        cout << "o:" << setw(10) << o_Count << setw(15) << o_Percent << "%" << endl;
        cout << "u:" << setw(10) << u_Count << setw(15) << u_Percent << "%" << endl;

        cout << "Do you want to try another (Y/N)? ";
        getline(cin, repeatProgram);
        cout << endl;

    } while(repeatProgram == "Y" || repeatProgram == "y");

    return 0;
}