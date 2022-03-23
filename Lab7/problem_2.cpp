/**
 * Filename: problem_2.cpp
 * Author: Anthony Grieco
 * Description: This program allows the user to add values for the weight, weightDate, size,
 *      feedHour,and food_type attributes to each of the animal objects specified in problem_1.
 *      The user is also allowed to change the name, cage, and enclosure of the first animal object.
 *      The program then stores each object in a vector and displays all the information for
 *      each object in the console.
 */

#include "Animal.cpp"
#include <iostream>
#include <vector>

using namespace std;

int main() {
    Animal animal1(1, "Lion", 1, 1);
    Animal animal2(2, "Zebra", 17, 12);
    Animal animal3(3, "Monkey", 35, 4);
    Animal animal4(4, "Coyote", 12, 7);

    string userInput; //Used to collect user input to manipulate animal objects
    string tempWord; //Used to convert food_type inputs to lowercase so they can be compared with the allowed foods
    bool feedHourAlreadyAssigned; //Used to check if the userInput for feedHour was already given to a different animal object

    vector <Animal> zooAnimals;

    zooAnimals.push_back(animal1);
    zooAnimals.push_back(animal2);
    zooAnimals.push_back(animal3);
    zooAnimals.push_back(animal4);

    //Cycles through each Animal Object and allows the User to plug in the designated information
    for (int i = 0; i < zooAnimals.size(); i++){

        //weight
        cout << "Enter Weight (Pounds) of " << zooAnimals[i].getName() << ":";
        getline(cin, userInput);
        do {
            if (stod(userInput) < 0.5){
                cin.clear();
                cout << "You must input a weight of at least 0.5 (pounds):";
                getline(cin, userInput);
                cout << endl;
            }
        } while(stod(userInput) < 0.5);
        zooAnimals[i].weight = stod(userInput);
        cin.clear();
        cout << endl;

        //weightDate
        cout << "The Last Time " << zooAnimals[i].getName() << " was Weighed (Year):";
        getline(cin, userInput);
        do {
            if (stoi(userInput) > 2021){
                cin.clear();
                cout << zooAnimals[i].getName() << " cannot have been weighed in a year that hasn't happened yet! Try again:";
                getline(cin, userInput);
                cout << endl;
            }

            else if (stoi(userInput) < 0){
                cin.clear();
                cout << zooAnimals[i].getName() << " cannot have been weighed in a negative year! Try again:";
                getline(cin, userInput);
                cout << endl;
            }

        } while (stoi(userInput) > 2021 || stoi(userInput) < 0);
        zooAnimals[i].weightDate = stoi(userInput);
        cin.clear();
        cout << endl;

        //size
        cout << "Size of " << zooAnimals[i].getName() << " ('S', 'M' or 'L'):";
        getline(cin, userInput);
        do {
            if(toupper(userInput[0]) != 'S' && toupper(userInput[0]) != 'M' && toupper(userInput[0]) != 'L'){
                cin.clear();
                cout << "You must input 'S' for small, 'M' for medium, or 'L' for large:";
                getline(cin, userInput);
                cout << endl;
            }
        } while(toupper(userInput[0]) != 'S' && toupper(userInput[0]) != 'M' && toupper(userInput[0]) != 'L');
        zooAnimals[i].size = toupper(userInput[0]);
        cin.clear();
        cout << endl;

        //feedHour
        cout << "Hour that " << zooAnimals[i].getName() << " is Fed (Military Time):";
        getline(cin, userInput);
        do {
            if (feedHourAlreadyAssigned == true){
                feedHourAlreadyAssigned = false;
                cin.clear();
                cout << "The Feed Hour " << userInput <<" was already assigned. Try again:";
                getline(cin, userInput);
                cout << endl;
            }

            if (stoi(userInput) < 1 || stoi(userInput) > 24){
                cin.clear();
                cout << "You must choose a value between 1 and 24:";
                getline(cin, userInput);
                cout << endl;
            }

            for (int j = i; j < zooAnimals.size(); j--){ //Checks if feedHour was already assigned
                if (stoi(userInput) == zooAnimals[j-1].feedHour){
                    feedHourAlreadyAssigned = true;
                }
            }
        } while(stoi(userInput) < 1 || stoi(userInput) > 24 || feedHourAlreadyAssigned == true);
        zooAnimals[i].feedHour = stoi(userInput);
        cin.clear();
        cout << endl;

        //food_type
        cout << "Food Type of " << zooAnimals[i].getName() << " ('Grass', 'Meat', 'Insect', 'Fruit' or 'Grain'):";
        getline(cin, userInput);
        do {
            cin.clear();
            tempWord.clear();
            for (int i = 0; i< userInput.size(); i++){ //Converts
                tempWord += tolower(userInput[i]);
            }

            if (tempWord != "grass" && tempWord != "meat" && tempWord != "insect" && tempWord != "fruit" && tempWord != "grain"){
                cout << "You must input one of the following Food Types ->" << endl << "'Grass', 'Meat', 'Insect', 'Fruit' or 'Grain':";
                getline(cin, userInput);
                cout << endl;
            }

        } while(tempWord != "grass" && tempWord != "meat" && tempWord != "insect" && tempWord != "fruit" && tempWord != "grain");
        userInput = tempWord;

        zooAnimals[i].food_type = userInput;
        cin.clear();
        cout << endl;
    }

    //Changing Name, Cage, and Enclosure of first animal object (starts out as Lion in cage 1 and enclosure 1 by default)
    cout << "You can change the name of the Animal " << zooAnimals[0].getName() <<". Please rename it:";
    getline(cin, userInput);
    zooAnimals[0].changeName(userInput);
    cin.clear();
    cout << endl;

    cout << "You can change the cage of the Animal " << zooAnimals[0].getName() <<". Please state which cage you are moving it to:";
    getline(cin, userInput);
    zooAnimals[0].changeCage(stoi(userInput));
    cin.clear();
    cout << endl;

    cout << "You can change the enclosure of the Animal " << zooAnimals[0].getName() <<". Please state which enclosure you are moving it to:";
    getline(cin, userInput);
    zooAnimals[0].changeEnclosure(stoi(userInput));
    cin.clear();
    cout << endl;

    for (int i = 0; i<zooAnimals.size(); i++){
        cout << zooAnimals[i].getID() << " " << zooAnimals[i].getName() << " " << zooAnimals[i].getCage() << " " << zooAnimals[i].getEnclosure() << " "
        << zooAnimals[i].weight << " " << zooAnimals[i].weightDate << " " << zooAnimals[i].size << " " << zooAnimals[i].feedHour << " "<< zooAnimals[i].food_type << endl;
    }

    return 0;
}