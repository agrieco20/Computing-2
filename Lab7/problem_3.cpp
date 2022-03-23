/**
 * Filename: problem_3.cpp
 * Author: Anthony Grieco
 * Description: This program uses the isHungry() method and a time inputted by the user to
 *      determine if an animal is hungry based on if the time entered matches the feedHour of the
 *      Animal object.
 */

#include "Animal.cpp"
#include <iostream>
#include <vector>

using namespace std;

int main() {
    Animal animal1(1, "Lion", 1, 1, 1200, 2020,'L', 23, "meat");
    Animal animal2(2, "Zebra", 17, 12, 880, 2021, 'L', 13, "grass");
    Animal animal3(3, "Monkey", 35, 4, 20, 2021, 'S', 5, "fruit");
    Animal animal4(4, "Coyote", 12, 7, 120, 2019, 'M', 23, "meat");

    vector <Animal> zooAnimals;

    zooAnimals.push_back(animal1);
    zooAnimals.push_back(animal2);
    zooAnimals.push_back(animal3);
    zooAnimals.push_back(animal4);

    int userInput; //Used by the user to determine the current hour (in military time)

    cout << "Please Input the Hour (Military Time):";
    cin >> userInput;
    do {
        if (userInput < 1 || userInput > 24){
            cin.clear();
            cout << "You must input an hour between 1 and 24:";
            cin >> userInput;
            cout << endl;
        }
    } while(userInput < 1 || userInput > 24);

    //Checks if the hour inputted by the user matches the feedHour of any of the specified Animal objects (if so, the first four attributes of that object are printed out)
    for (int i = 0; i < zooAnimals.size(); i++){
        if (zooAnimals[i].isHungry(userInput) == true){
            cout << zooAnimals[i].getID() << " " << zooAnimals[i].getName() << " " << zooAnimals[i].getCage() << " " << zooAnimals[i].getEnclosure() << endl;
        }
    }
    return 0;
}