/**
 * Filename: Datetime.cpp
 * Author: Anthony Grieco
 * Description: Creates a Datetime class for problem_1
 */

#include <string>
#include <ctime>

using namespace std;

class Datetime{
    public:

    string getDateStr(){
        //The following conditional statements are used to format the return value(places an extra 0 before either months or days depending on the time)
        if (Datetime().month() < 10 && Datetime().day() > 9){
            return "0" + to_string(Datetime().month()) + "/" + to_string(Datetime().day()) + "/" + to_string(Datetime().year());
        }

        else if (Datetime().month() > 9 && Datetime().day() < 10){
            return to_string(Datetime().month()) + "/0" + to_string(Datetime().day()) + "/" + to_string(Datetime().year());
        }

        else if (Datetime().month() < 10 && Datetime().day() < 10){
            return "0" + to_string(Datetime().month()) + "/0" + to_string(Datetime().day()) + "/" + to_string(Datetime().year());
        }

        else {
            return to_string(Datetime().month()) + "/" + to_string(Datetime().day()) + "/" + to_string(Datetime().year());
        }

    }

    string getTimeStr(){
        int currentHour = Datetime().hour24();

        if (currentHour > 12){ //If past, noon, subtracts 12 from the hour
            currentHour -= 12;
        }

        //The following conditional statements are used to format the return value(places an extra 0 before either minutes or seconds depending on the time)
        if (Datetime().min() < 10 && Datetime().sec() > 9){
            return to_string(currentHour) + ":0" + to_string(Datetime().min()) + ":" + to_string(Datetime().sec()) +
                   " " + Datetime().hour();
        }

        else if (Datetime().min() > 9 && Datetime().sec() < 10){
            return to_string(currentHour) + ":" + to_string(Datetime().min()) + ":0" + to_string(Datetime().sec()) +
                   " " + Datetime().hour();
        }

        else if (Datetime().min() < 10 && Datetime().sec() < 10){
            return to_string(currentHour) + ":0" + to_string(Datetime().min()) + ":0" + to_string(Datetime().sec()) +
                   " " + Datetime().hour();
        }

        else {
            return to_string(currentHour) + ":" + to_string(Datetime().min()) + ":" + to_string(Datetime().sec()) +
                   " " + Datetime().hour();
        }
    }

    string getTimeStr24(){
        int currentHour = Datetime().hour24();

        //The following conditional statements are used to format the return value(places an extra 0 before either minutes or seconds depending on the time)
        if (Datetime().min() < 10 && Datetime().sec() > 9){
            return to_string(currentHour) + ":0" + to_string(Datetime().min()) + ":" + to_string(Datetime().sec()) +
                   " " + Datetime().hour();
        }

        else if (Datetime().min() > 9 && Datetime().sec() < 10){
            return to_string(currentHour) + ":" + to_string(Datetime().min()) + ":0" + to_string(Datetime().sec()) +
                   " " + Datetime().hour();
        }

        else if (Datetime().min() < 10 && Datetime().sec() < 10){
            return to_string(currentHour) + ":0" + to_string(Datetime().min()) + ":0" + to_string(Datetime().sec()) +
                   " " + Datetime().hour();
        }

        else {
            return to_string(currentHour) + ":" + to_string(Datetime().min()) + ":" + to_string(Datetime().sec()) +
                   " " + Datetime().hour();
        }
    }

        int day(){
            time_t t = time(0);
            tm * local_time = localtime(&t);
            return local_time->tm_mday;
        }

        int month(){
            time_t t = time(0);
            tm * local_time = localtime(&t);
            return local_time->tm_mon + 1;
        }

        int year(){
            time_t t = time(0);
            tm * local_time = localtime(&t);
            return local_time->tm_year + 1900;
        }

        string hour(){
            if(Datetime().hour24() > 12){ //returns pm if past noon, otherwise returns am
                return "p.m.";
            }

            else {
                return "a.m.";
            }
        }

        int hour24(){
            time_t t = time(0);
            tm * local_time = localtime(&t);
            return local_time->tm_hour;
        }

        int min(){
            time_t t = time(0);
            tm * local_time = localtime(&t);
            return local_time->tm_min;
        }

        int sec(){
            time_t t = time(0);
            tm * local_time = localtime(&t);
            return local_time->tm_sec;
        }
};