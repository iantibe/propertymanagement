#ifndef LOGINSCREEN_H
#define LOGINSCREEN_H

#include "accessscreen.h"

class Loginscreen : Accessscreen {
private:
    string instruction;
public:
    void displayScreen() override;
    void setInstructions(string);
    string getInstructions();
};

#endif // LOGINSCREEN_H
