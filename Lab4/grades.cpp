/*****
 * grades.cpp
 * function to create a 25 item random vector of double values in
 * the range of 56.5 - 100
 * */

//Original Code provided by Dr. Albina to the class

#include "grades.h"
#include <vector>
#include <random> //Was not in original code but fixed errors throughout related to random generation

std::vector<double> getGrades() {
    const double MIN = 56.5;
    const double MAX = 100.00;

    std::vector<double> grades;
    for (int i = 0; i <25; i ++){
        grades.push_back((MAX - MIN) * ( (double)rand() / (double)RAND_MAX ) + MIN);
    }
    return grades;
}