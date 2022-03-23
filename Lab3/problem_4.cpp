/************************
 * Filename: problem_4.cpp
 * Author: Anthony Grieco
 * Description: This program provides the user a menu driven user interface that provides conversion from
 *      imperial measures to metric measures. Your program must provide conversion to and from Miles<->Kilometers,
 *      Gallons<->Liters, Yards<->Meters,Inches<->Centimeters. The user can choose whether they want to convert
 *      from Imperial to Metric or Metric to Imperial, and then choose which of the above conversions they wish
 *      to perform. The user should be able to choose to convert something else as many times as they wish.
 ***********************/

#include <iostream>

using namespace std;

bool programRepeat();
bool repeatProgram;

int main(){
    int imperialOrMetric, conversionChoice;
    double valueToBeConverted, convertedValue;
    bool invalidInput;

    cout<<fixed;
    cout.precision(2);
    do{
        repeatProgram = false;
        cout << "1.Metric --> Imperial\t2.Imperial --> Metric\n"
                "Please type the number corresponding to the above system of measuring would you like to convert to: ";
        cin >> imperialOrMetric;
        cout << endl;

        switch (imperialOrMetric) {
            case 1: //Metric --> Imperial
                do{
                    cout << "You have chosen to convert from the Metric System to the Imperial System.\n"
                            "1.Kilometers --> Miles\t2.Liters --> Gallons\n"
                            "3.Meters --> Yards\t4.Centimeters --> Inches\n"
                            "Please type the number of the conversion calculator you would like to use: ";
                    cin >> conversionChoice;
                    cout << endl;

                    switch (conversionChoice) {
                        case 1:
                            invalidInput = false;
                            cout << "How many kilometers would you like to convert into miles? ";
                            cin >> valueToBeConverted;
                            cout << endl;

                            convertedValue = valueToBeConverted * 0.6213;
                            cout << valueToBeConverted << " Kilometers = " << convertedValue << " Miles" << endl;
                            break;

                        case 2:
                            invalidInput = false;
                            cout << "How many liters would you like to convert into gallons? ";
                            cin >> valueToBeConverted;
                            cout << endl;

                            convertedValue = valueToBeConverted * 0.2641;
                            cout << valueToBeConverted << " Liters = " << convertedValue << " Gallons " << endl;
                            break;

                        case 3:
                            invalidInput = false;
                            cout << "How many meters would you like to convert into yards? ";
                            cin >> valueToBeConverted;
                            cout << endl;

                            convertedValue = valueToBeConverted * 1.0936;
                            cout << valueToBeConverted << " Meters = " << convertedValue << " Yards " << endl;
                            break;

                        case 4:
                            invalidInput = false;
                            cout << "How many centimeters would you like to convert into inches? ";
                            cin >> valueToBeConverted;
                            cout << endl;

                            convertedValue = valueToBeConverted * 0.3937;
                            cout << valueToBeConverted << " Centimeters = " << convertedValue << " Inches " << endl;
                            break;

                        default:
                            cout << "Your input was not a 1, 2, 3, or 4. Please try again." << endl;
                            invalidInput = true;
                            break;
                    }
                } while(invalidInput==true);
                programRepeat();
                break;

            case 2: //Imperial --> Metric
                do{
                    cout << "You have chosen to convert from the Metric System to the Imperial System.\n"
                            "1.Miles --> Kilometers\t2.Gallons --> Liters\n"
                            "3.Yards --> Meters\t4.Inches --> Centimeters\n"
                            "Please type the number of the conversion calculator you would like to use: ";
                    cin >> conversionChoice;
                    cout << endl;

                    switch (conversionChoice) {
                        case 1:
                            invalidInput = false;
                            cout << "How many miles would you like to convert into kilometers? ";
                            cin >> valueToBeConverted;
                            cout << endl;

                            convertedValue = valueToBeConverted * 1.6093;
                            cout << valueToBeConverted << " Miles = " << convertedValue << " Kilometers" << endl;
                            break;

                        case 2:
                            invalidInput = false;
                            cout << "How many gallons would you like to convert into liters? ";
                            cin >> valueToBeConverted;
                            cout << endl;

                            convertedValue = valueToBeConverted * 3.7854;
                            cout << valueToBeConverted << " Gallons = " << convertedValue << " Liters " << endl;
                            break;

                        case 3:
                            invalidInput = false;
                            cout << "How many yards would you like to convert into meters? ";
                            cin >> valueToBeConverted;
                            cout << endl;

                            convertedValue = valueToBeConverted * 0.9144;
                            cout << valueToBeConverted << " Yards = " << convertedValue << " Meters " << endl;
                            break;

                        case 4:
                            invalidInput = false;
                            cout << "How many inches would you like to convert into centimeters? ";
                            cin >> valueToBeConverted;
                            cout << endl;

                            convertedValue = valueToBeConverted * 2.5400;
                            cout << valueToBeConverted << " Inches = " << convertedValue << " Centimeters " << endl;
                            break;

                        default:
                            cout << "Your input was not a 1, 2, 3, or 4. Please try again." << endl;
                            invalidInput = true;
                            break;
                    }
                } while(invalidInput==true);
                programRepeat();
                break;

            default:
                cout << "Your input must be either a 1 or a 2. Please try again." << endl << endl;
                invalidInput = true;
                break;
        }
    }while (invalidInput == true || repeatProgram == true);

    return 0;
}

bool programRepeat(){
    string userAnswerProgramRepeat;
    cout << "Would you like to convert another value? (Please answer 'Yes' or 'No') ";
    cin >> userAnswerProgramRepeat;
    cout << endl;

    if (userAnswerProgramRepeat == "Yes" || userAnswerProgramRepeat == "yes"){
        repeatProgram = true;
    }
    else{
        repeatProgram = false;
    }
    return repeatProgram;
}