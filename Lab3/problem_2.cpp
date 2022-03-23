/************************
 * Filename: problem_2.cpp
 * Author: Anthony Grieco
 * Description: This program will provide a currency conversion service to the user.
 *      It will convert from the US Dollar to one of the following currencies: Euro, Yen, Rupee, Pound.
 *      A menu is provided to the user in order to allow them to choose the currency they desire to convert to
 *      and the dollar amount to be converted. The output will be displayed to 2 decimal points.
 ***********************/

#include <iostream>

using namespace std;

void dollarToEuro(double);
void dollarToYen(double);
void dollarToRupee(double);
void dollarToPound(double);

int main(){
    string repeatProgram;
    int conversionChoice;
    double dollarValue = 0.0;

    do {
        cout << "You can convert US Dollars to one of the following currencies: \n "
                "1. Euro \t 2. Japanese Yen \t 3. Indian Rupee \t 4. Pound Sterling\n"
                "Please input the number corresponding to the currency you would like to convert to:" << endl;
        cin >> conversionChoice;

        do{
            if (conversionChoice < 1 || conversionChoice > 4) {
                cout << "You must choose a value corresponding to one of the following currencies: \n"
                        "1. Euro \t 2. Japanese Yen \t 3. Indian Rupee \t 4. Pound Sterling \n";
                cin >> conversionChoice;
            }
        } while (conversionChoice < 1 || conversionChoice > 4);

        if (conversionChoice == 1){
            cout << "How much money (in US Dollars) would you like convert to Euros? $";
            cin >> dollarValue;
            do{
                if (dollarValue < 0){
                    cout << "You cannot convert a negative amount of money. \nHow much money (in US Dollars) would you like convert to Euros? $";
                    cin >> dollarValue;
                }
            }
            while (dollarValue < 0);

            dollarToEuro(dollarValue);
        }

        if (conversionChoice == 2){
            cout << "How much money (in US Dollars) would you like convert to Yen? $";
            cin >> dollarValue;
            do{
                if (dollarValue < 0){
                    cout << "You cannot convert a negative amount of money. \nHow much money (in US Dollars) would you like convert to Yen? $";
                    cin >> dollarValue;
                }
            }
            while (dollarValue < 0);

            dollarToYen(dollarValue);
        }

        if (conversionChoice == 3){
            cout << "How much money (in US Dollars) would you like convert to Rupees? $";
            cin >> dollarValue;
            do{
                if (dollarValue < 0){
                    cout << "You cannot convert a negative amount of money. \nHow much money (in US Dollars) would you like convert to Rupees? $";
                    cin >> dollarValue;
                }
            }
            while (dollarValue < 0);

            dollarToRupee(dollarValue);
        }

        if (conversionChoice == 4){
            cout << "How much money (in US Dollars) would you like convert to Pounds? $";
            cin >> dollarValue;
            do{
                if (dollarValue < 0){
                    cout << "You cannot convert a negative amount of money. \nHow much money (in US Dollars) would you like convert to Pounds? $";
                    cin >> dollarValue;
                }
            }
            while (dollarValue < 0);

            dollarToPound(dollarValue);
        }

        cout << endl;
        cout << "Would you like to use this currency conversion calculator again? (Please answer 'Yes' or 'No'.)" << endl;
        cin >> repeatProgram;
        cout << endl;

    } while(repeatProgram == "Yes" || repeatProgram == "yes");

}
//Dollar to Euro Conversion:
void dollarToEuro(double dollarConversion){
    cout << fixed;
    cout.precision(2);

    double euroValue = dollarConversion * 0.82;
    cout << "US Dollars Converted to Euros: \n$" << dollarConversion << " ---> " << euroValue << " Euros";
}

//Dollar to Yen Conversion:
void dollarToYen(double dollarConversion){
    cout << fixed;
    cout.precision(2);

    double yenValue = dollarConversion * 105.00;
    cout << "US Dollars Converted to Yen: \n$" << dollarConversion << " ---> " << yenValue << " Yen";
}

//Dollar to Rupee Conversion:
void dollarToRupee(double dollarConversion){
    cout << fixed;
    cout.precision(2);

    double rupeeValue = dollarConversion * 72.45;
    cout << "US Dollars Converted to Rupees: \n$" << dollarConversion << " ---> " << rupeeValue << " Rupees";
}

//Dollar to Pound Conversion:
void dollarToPound(double dollarConversion){
    cout << fixed;
    cout.precision(2);

    double poundValue = dollarConversion * 0.71;
    cout << "US Dollars Converted to Pounds: \n$" << dollarConversion << " ---> " << poundValue << " Pounds";
}