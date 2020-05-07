#include "loginscreen.h"
#include "iostream"
#include "constants.h"

void Loginscreen::displayScreen(){
    setHeader("Welecome to the Rental Management system.");
    setInstructions("Enter your user name and password to begin.");

    cout << getHeader() << endl << endl;
    cout << getInstructions() << "Type " << exitWord << " to exit program" << endl;
}

string Loginscreen::getInstructions(){
    return instruction;
}

void Loginscreen::setInstructions(string i){
    this->instruction = i;
}
