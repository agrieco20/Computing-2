/**
 * Filename: problem_4.cpp
 * Author: Anthony Grieco
 * Description: This program uses the file named "our_zoo.csv" to create Animal objects based
 *      on that data given in the file. Each Animal Object is stored in a vector. A menu is
 *      then provided so that a user can find an animal based on the following options:
 *      1. Size
 *      2. ID
 *      3. Enclosure
 *      4. Hunger
 *      5. Needs to be Weighed
 *      6. Exits the Program
 */

#include "Animal.cpp"
#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

void displayBySize(string userInput);
void displayByID(string userInput);
void displayByEnclosure(string userInput);
void displayByHunger(string userInput);
void displayByWeightDate(string userInput);

vector <Animal> zooAnimals; //Used to store the Animal objects

int main() {
    string userInput; //Used by the user to input commands, fill in information, etc.
    string lineRetrieved; //Used to retrieve lines from "our_zoo.csv" file
    string tempText; //Used to temporarily hold characters before they are assigned to an Animal Object
    bool continueSearching = true; //Used in case 6 to end program

    string infileName = "our_zoo.csv";
    ifstream infile;
    infile.open(infileName, ios::in);

    //The following are used to check whether the corresponding attribute has been fulfilled
    bool ID_found, name_found, cageNum_found, enclosure_found, weight_found, weightDate_found, size_found, feedHour_found, foodType_found;

    //The following are used to temporarily store the inputs that will later become the attributes of the new Animal object
    string ID_input, name_input, cageNum_input, enclosure_input, weight_input, weightDate_input, size_input, feedHour_input, foodType_input;

    vector <string> lines; //Used to store each line of


    if (infile.is_open()){
        while(getline(infile, lineRetrieved)){
            lines.push_back(lineRetrieved);
        }
    }

    lines.erase(lines.begin()); //Deletes the first line of the "our_zoo.csv" file so program can create the Animal Objects without the descriptions in this line causing an error

    for (string line: lines){
        ID_found = false, name_found = false, cageNum_found = false, enclosure_found = false, weight_found = false, weightDate_found = false, size_found = false, feedHour_found = false, foodType_found = false; //Reset

        //Assigns each attribute for the new Animal object based on the position of line within the vector lines
        for (int i = 0; i < line.size(); i++){

            if (i == line.size()-1){
                tempText += line[i];
            }

            if (line[i]==',' || i == line.size()-1){
                if (ID_found == false){
                    ID_found = true;
                    ID_input = tempText;
                }

                else if (name_found == false){
                    name_found = true;
                    name_input = tempText;
                }

                else if (cageNum_found == false){
                    cageNum_found = true;
                    cageNum_input = tempText;
                }

                else if (enclosure_found == false){
                    enclosure_found = true;
                    enclosure_input = tempText;
                }

                else if (weight_found == false){
                    weight_found = true;
                    weight_input = tempText;
                }

                else if (weightDate_found == false){
                    weightDate_found = true;
                    weightDate_input = tempText;
                }

                else if (size_found == false){
                    size_found = true;
                    size_input = tempText;
                }

                else if (feedHour_found == false){
                    feedHour_found = true;
                    feedHour_input = tempText;
                }

                else if (foodType_found == false){
                    foodType_found = true;
                    foodType_input = tempText;
                }
                tempText = "";
            }
            else{
                tempText += line[i];
            }
        }
        //Creates a new Animal object for each line of the "our_zoo.csv" file (exception being the first line because it was deleted)
        Animal animal(stoi(ID_input), name_input, stoi(cageNum_input), stoi(enclosure_input), stod(weight_input), stoi(weightDate_input), size_input[0], stoi(feedHour_input), foodType_input);
        zooAnimals.push_back(animal); //Adds the new Animal object to the vector
    }

    //Menu for the User
    do{
        cout << "Please choose a number that corresponds with one of the following operations:" << endl
        << "1. Search by Size\t2. Search by ID\t\t\t3. Search by Enclosure"<< endl
        << "4. Search by Hunger\t5. Search by Last Weight Date\t6. Exit Search" <<endl
        << "Your Choice:";
        getline(cin,userInput);
        cout << endl;
        do{
            if (stoi(userInput) < 1 || stoi(userInput) > 6){
                cin.clear();
                cout << "You must choose a number corresponding to one of the following operations:" << endl
                << "1. Search by Size\t2. Search by ID\t\t\t3. Search by Enclosure"<< endl
                << "4. Search by Hunger\t5. Search by Last Weight Date\t6. Exit Search" <<endl
                << "Your Choice:";
                getline(cin,userInput);
                cout << endl;
            }
        } while(stoi(userInput) < 1 || stoi(userInput) > 6);

        cin.clear();

        switch (stoi(userInput)) {
            case 1: //Sort by Size
                displayBySize(userInput);
                break;

            case 2: //Sort by ID
                displayByID(userInput);
                break;

            case 3: //Sort by Enclosure
                displayByEnclosure(userInput);
                break;

            case 4: //Sort by Hunger
                displayByHunger(userInput);
                break;

            case 5: //Sort by WeightDate
                displayByWeightDate(userInput);
                break;

            case 6: //Exit
                continueSearching = false;
                cout << "Thank you for using this program." << endl;
                break;
        }
    } while(continueSearching == true);

    return 0;
}

//Each Function corresponds to a "case" used in the Menu
void displayBySize(string userInput) { //Case 1
    cin.clear();
    cout << "What sized animal do you wish to see? ('S', 'M' or 'L'):";
    getline(cin, userInput);

    do {//Verification
        if (toupper(userInput[0]) != 'S' && toupper(userInput[0]) != 'M' && toupper(userInput[0]) != 'L') {
            cin.clear();
            cout << "You must input 'S' for small, 'M' for medium, or 'L' for large:";
            getline(cin, userInput);
            cout << endl;
        }
    } while (toupper(userInput[0]) != 'S' && toupper(userInput[0]) != 'M' && toupper(userInput[0]) != 'L');

    for (int i = 0; i < zooAnimals.size(); i++) { //Search
        if(zooAnimals[i].size == toupper(userInput[0])){
            cout << zooAnimals[i].getID() << " " << zooAnimals[i].getName() << " " << zooAnimals[i].getCage() << " " << zooAnimals[i].getEnclosure() << endl;
        }
    }
    cin.clear();
    cout << endl;
}

void displayByID(string userInput){ //Case 2
    bool repeatProgram;
    bool noMatches;

    do{
        repeatProgram = false;
        noMatches = true;
        cin.clear();
        cout << "Please insert the ID of the Animal you are looking for:";
        getline(cin, userInput);
        cout << endl;

        do{ //Verification
            if(stoi(userInput) < 0){
                cout << "An Animal ID cannot be negative. Please insert the ID of the Animal you are looking for:";
                getline(cin, userInput);
                cout << endl;
            }
        }while(stoi(userInput) < 0);

        for (int i = 0; i < zooAnimals.size(); i++) { //Search
            if (zooAnimals[i].getID() == stoi(userInput)){
                noMatches = false;
                cout << zooAnimals[i].getID() << " " << zooAnimals[i].getName() << " " << zooAnimals[i].getCage() << " " << zooAnimals[i].getEnclosure() << " "
                     << zooAnimals[i].weight << " " << zooAnimals[i].weightDate << " " << zooAnimals[i].size << " " << zooAnimals[i].feedHour << " "<< zooAnimals[i].food_type << endl << endl;
            }
        }

        if (noMatches == true){ //Checks to see if the user wants to try entering another value since the one they put in yielded no data
            cout << "Unfortunately, the ID " << userInput << " did not match any ID in this data base. Would you like to try a different ID?";
            getline(cin, userInput);
            cout << endl;
            if (toupper(userInput[0])=='Y'){
                repeatProgram = true;
            }
        }

    } while(repeatProgram == true);
}

void displayByEnclosure(string userInput){ //Case 3
    cin.clear();
    bool repeatProgram;
    bool noMatches;

    do{
        repeatProgram = false;
        noMatches = true;
        cin.clear();
        cout << "Please insert the Enclosure number of the Animal you are looking for:";
        getline(cin, userInput);
        cout << endl;

        do{ //Verification
            if(stoi(userInput) < 0){
                cout << "An Animal Enclosure cannot be negative. Please insert the Enclosure number related to the Animal you are looking for:";
                getline(cin, userInput);
                cout << endl;
            }
        }while(stoi(userInput) < 0);

        for (int i = 0; i < zooAnimals.size(); i++) { //Search
            if (zooAnimals[i].getEnclosure() == stoi(userInput)){
                noMatches = false;
                cout << zooAnimals[i].getID() << " " << zooAnimals[i].getName() << " " << zooAnimals[i].getCage() << " " << zooAnimals[i].feedHour << endl << endl;
            }
        }

        if (noMatches == true){ //Checks to see if the user wants to try entering another value since the one they put in yielded no data
            cout << "Unfortunately, the number " << userInput << " did not correspond to any Enclosure in this data base. Would you like to try a different number?";
            getline(cin, userInput);
            cout << endl;
            if (toupper(userInput[0])=='Y'){
                repeatProgram = true;
            }
        }
    } while(repeatProgram == true);
}

void displayByHunger(string userInput){ //Case 4
    cin.clear();
    bool repeatProgram;
    bool noMatches;

    do{
        repeatProgram = false;
        noMatches = true;
        cin.clear();

        cout << "Please input the current Hour (Military Time):";
        getline(cin, userInput);

        do { //Verification
            if (stoi(userInput) < 1 || stoi(userInput) > 24){
                cin.clear();
                cout << "You must input an hour between 1 and 24:";
                getline(cin,userInput);
                cout << endl;
            }
        } while(stoi(userInput) < 1 || stoi(userInput) > 24);

        cin.clear();

        for (int i = 0; i < zooAnimals.size(); i++){ //Search
            if (zooAnimals[i].isHungry(stoi(userInput)) == true){
                if (noMatches == true){
                    cout << "The following animals are hungry:" << endl;
                    noMatches = false;
                }
                cout << zooAnimals[i].getID() << " " << zooAnimals[i].getCage() << " " << zooAnimals[i].getEnclosure() << " " << zooAnimals[i].feedHour << " " << zooAnimals[i].food_type << endl << endl;
            }
        }

        if (noMatches == true){ //Checks to see if the user wants to try entering another value since the one they put in yielded no data
            cout << "Unfortunately, there are no animals that are fed at " << userInput << ":00." << endl << "Would you like to try a different hour?";
            getline(cin, userInput);
            cout << endl;
            if (toupper(userInput[0])=='Y'){
                repeatProgram = true;
            }
        }
    } while(repeatProgram == true);
}

void displayByWeightDate(string userInput){ //Case 5
    cin.clear();

    cout << "Please enter the current year:";
    getline(cin, userInput);
    do {
        if (stoi(userInput) < 0){
            cin.clear();
            cout << "The year cannot be negative. Please try again:";
            getline(cin, userInput);
            cout << endl;
        }

    } while (stoi(userInput) < 0);

    cout<< "The following animals have not been weighed in " << userInput << ":" << endl;

    for (int i = 0; i < zooAnimals.size(); i++) { //Search
        if (zooAnimals[i].weightDate != stoi(userInput)){
            cout << zooAnimals[i].getID() << " " << zooAnimals[i].getName() << " " << zooAnimals[i].getCage() << " " << zooAnimals[i].getEnclosure() << " " << zooAnimals[i].weight << " " << zooAnimals[i].weightDate << endl << endl;
        }
    }
    cin.clear();
    cout << endl;
}