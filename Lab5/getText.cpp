/**
 * getText.cpp
 * function to create a vector of lines of text
 */

//Original Code provided by Dr. Albina to the class

#include "getText.h"
#include <vector>
#include <string>
#include <sstream>

std::vector<std::string> getText() {
    std::vector<std::string> txtVector;
    std::string lines {"Two households, both alike in dignity\n"
                       "(In fair Verona, where we lay our scene),\n"
                       "From ancient grudge break to new mutiny,\n"
                       "Where civil blood makes civil hands unclean.\n"
                       "From forth the fatal loins of these two foes\n"
                       "A pair of star-crossed lovers take their life;\n"
                       "Whose misadventured piteous overthrows\n"
                       "Doth with their death bury their parents rage,\n"
                       "Which, but their children traffic of our stage;\n"
                       "The which, if you with patient ears attend,\n"
                       "What here shall miss, our toil shall strive to mend.\n"}; //83-84 Words (depending on if hyphen counts as punct)
    std::istringstream ss(lines);
    std::string token="\n";
    while(std::getline(ss, token, '\n')) {
        txtVector.push_back(token);
    }
    return txtVector;
}