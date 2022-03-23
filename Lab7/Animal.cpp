/**
 * Filename: Animal.cpp
 * Author: Anthony Grieco
 * Description: Creates an Animal Class
 */

#include <iostream>

using namespace std;

class Animal{
    private:
        int id;
        string name;
        int cage_num;
        int enclosure_num;

    public:
        double weight;
        int weightDate;
        char size; //'S', 'M', or 'L'
        int feedHour; //1-24
        string food_type; //'Grass', 'Meat', 'Insect', 'Fruit' or 'Grain'

        Animal(int id, string name, int cage_num, int enclosure_num, double weight = 0.5, int weightDate = 2021, char size = 'S', int feedHour = 1, string food_type = "grass"){
            this->id = id;
            this->name = name;
            this->cage_num = cage_num;
            this->enclosure_num = enclosure_num;
            this->weight = weight;
            this->weightDate = weightDate;
            this->size = size;
            this->feedHour = feedHour;
            this->food_type = food_type;
        }

        int getID(){
            return id;
        }

        void changeName(string newName){
            name = newName;
        }

        string getName(){
            return name;
        }

        void changeEnclosure(int num){
            enclosure_num = num;
        }

        int getEnclosure(){
            return enclosure_num;
        }

        void changeCage(int cageNum){
            cage_num = cageNum;
        }

        int getCage(){
            return cage_num;
        }

        bool isHungry(int curHour){
            if (curHour == feedHour){
                return true; //Is Hungry
            }
            else{
                return false; //Is Not Hungry
            }
        }
};