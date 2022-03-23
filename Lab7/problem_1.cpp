/**
 * Filename: problem_1.cpp
 * Author: Anthony Grieco
 * Description: After creating an Animal Class, this program will use that class to both
 *      create and display 4 Animal Objects (the user is unable to interact with them other
 *      than seeing the printed out objects).
 */

#include "Animal.cpp"
#include <iostream>

using namespace std;

int main() {
    Animal animal1(1, "Lion", 1, 1);
    Animal animal2(2, "Zebra", 17, 12);
    Animal animal3(3, "Monkey", 35, 4);
    Animal animal4(4, "Coyote", 12, 7);

    cout << animal1.getID() << " " << animal1.getName() << " " << animal1.getCage() << " " << animal1.getEnclosure() << endl;
    cout << animal2.getID() << " " << animal2.getName() << " " << animal2.getCage() << " " << animal2.getEnclosure() << endl;
    cout << animal3.getID() << " " << animal3.getName() << " " << animal3.getCage() << " " << animal3.getEnclosure() << endl;
    cout << animal4.getID() << " " << animal4.getName() << " " << animal4.getCage() << " " << animal4.getEnclosure() << endl;

    return 0;
}