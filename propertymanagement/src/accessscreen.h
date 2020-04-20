#ifndef ACCESSSCREEN_H
#define ACCESSSCREEN_H

#include <string>

using namespace std;

class Accessscreen{
private:
    string header;
public:
    virtual void displayScreen() = 0;
    void setHeader(string);
    string getHeader();
};

#endif // ACCESSSCREEN_H


