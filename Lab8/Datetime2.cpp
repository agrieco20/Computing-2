/**
 * Filename: Datetime2.cpp
 * Author: Anthony Grieco
 * Description: Creates a Datetime2 class for problem_2
 */

#include <string>
#include <ctime>

using namespace std;

class Datetime2{
    public:

    struct dt{
        int year = 0;
        int month = 0;
        int day= 0;
        int hour = 0;
        int min = 0;
        int sec = 0;

    } datetime;

    Datetime2() {}

    void update(){
        datetime.year = c_year();
        datetime.month = c_month();
        datetime.day = c_day();
        datetime.hour = c_hour24();
        datetime.min = c_min();
        datetime.sec = c_sec();
    }

    string getCurDateStr(){
        //The following conditional statements are used to format the return value(places an extra 0 before either months or days depending on the time)
        if (Datetime2().c_month() < 10 && Datetime2().c_day() > 9){
            return "0" + to_string(Datetime2().c_month()) + "/" + to_string(Datetime2().c_day()) + "/" + to_string(Datetime2().c_year());
        }

        else if (Datetime2().c_month() > 9 && Datetime2().c_day() < 10){
            return to_string(Datetime2().c_month()) + "/0" + to_string(Datetime2().c_day()) + "/" + to_string(Datetime2().c_year());
        }

        else if (Datetime2().c_month() < 10 && Datetime2().c_day() < 10){
            return "0" + to_string(Datetime2().c_month()) + "/0" + to_string(Datetime2().c_day()) + "/" + to_string(Datetime2().c_year());
        }

        else {
            return to_string(Datetime2().c_month()) + "/" + to_string(Datetime2().c_day()) + "/" + to_string(Datetime2().c_year());
        }

    }

    string getCurTimeStr(){
        int currentHour = Datetime2().c_hour24();

        if (currentHour > 12){ //If past, noon, subtracts 12 from the hour
            currentHour -= 12;
        }

        //The following conditional statements are used to format the return value(places an extra 0 before either minutes or seconds depending on the time)
        if (Datetime2().c_min() < 10 && Datetime2().c_sec() > 9){
            return to_string(currentHour) + ":0" + to_string(Datetime2().c_min()) + ":" + to_string(Datetime2().c_sec()) +
                   " " + Datetime2().c_hour();
        }

        else if (Datetime2().c_min() > 9 && Datetime2().c_sec() < 10){
            return to_string(currentHour) + ":" + to_string(Datetime2().c_min()) + ":0" + to_string(Datetime2().c_sec()) +
                   " " + Datetime2().c_hour();
        }

        else if (Datetime2().c_min() < 10 && Datetime2().c_sec() < 10){
            return to_string(currentHour) + ":0" + to_string(Datetime2().c_min()) + ":0" + to_string(Datetime2().c_sec()) +
                   " " + Datetime2().c_hour();
        }

        else {
            return to_string(currentHour) + ":" + to_string(Datetime2().c_min()) + ":" + to_string(Datetime2().c_sec()) +
                   " " + Datetime2().c_hour();
        }
    }

    string getTimeStr24(){
        int currentHour = Datetime2().c_hour24();

        //The following conditional statements are used to format the return value(places an extra 0 before either minutes or seconds depending on the time)
        if (Datetime2().c_min() < 10 && Datetime2().c_sec() > 9){
            return to_string(currentHour) + ":0" + to_string(Datetime2().c_min()) + ":" + to_string(Datetime2().c_sec()) +
                   " " + Datetime2().c_hour();
        }

        else if (Datetime2().c_min() > 9 && Datetime2().c_sec() < 10){
            return to_string(currentHour) + ":" + to_string(Datetime2().c_min()) + ":0" + to_string(Datetime2().c_sec()) +
                   " " + Datetime2().c_hour();
        }

        else if (Datetime2().c_min() < 10 && Datetime2().c_sec() < 10){
            return to_string(currentHour) + ":0" + to_string(Datetime2().c_min()) + ":0" + to_string(Datetime2().c_sec()) +
                   " " + Datetime2().c_hour();
        }

        else {
            return to_string(currentHour) + ":" + to_string(Datetime2().c_min()) + ":" + to_string(Datetime2().c_sec()) +
                   " " + Datetime2().c_hour();
        }
    }

    int c_day(){
        time_t t = time(0);
        tm * local_time = localtime(&t);
        return local_time->tm_mday;
    }

    int c_month(){
        time_t t = time(0);
        tm * local_time = localtime(&t);
        return local_time->tm_mon + 1;
    }

    int c_year(){
        time_t t = time(0);
        tm * local_time = localtime(&t);
        return local_time->tm_year + 1900;
    }

    string c_hour(){
        if(Datetime2().c_hour24() > 12){ //returns pm if past noon, otherwise returns am
            return "p.m.";
        }

        else {
            return "a.m.";
        }
    }

    int c_hour24(){
        time_t t = time(0);
        tm * local_time = localtime(&t);
        return local_time->tm_hour;
    }

    int c_min(){
        time_t t = time(0);
        tm * local_time = localtime(&t);
        return local_time->tm_min;
    }

    int c_sec(){
        time_t t = time(0);
        tm * local_time = localtime(&t);
        return local_time->tm_sec;
    }

    void operator++(){ //Adds 1 when operator is called
        datetime.year += 1;
    }

    void operator--(){ //Subtracts 1 when operator is called
        datetime.year -= 1;
    }

    void operator++(int){ //Adds 1 when operator is called
        datetime.year += 1;
    }

    void operator--(int){ //Subtracts 1 when operator is called
        datetime.year -= 1;
    }

    void operator+(int n){ //Adds 'n' when operator is called, ex: 20
        datetime.year += n;
    }

    void operator-(int n){ //Subtracts 'n' when operator is called, ex: 20
        datetime.year -= n;
    }
};