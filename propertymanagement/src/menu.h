#ifndef MENU_H
#define MENU_H

#include <string>
#include <vector>
#include "menuitem.h"

using namespace std;

class Menu{
public:
    string title;
public:
    void drawmenu(vector<Menuitem>);
    virtual void display() = 0;
    int selection(int);
    string getTitle();
    void setTitle(string);
    Menu(string title);
};

#endif // MENU_H
