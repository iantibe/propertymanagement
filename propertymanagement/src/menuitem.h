#ifndef MENUITEM_H
#define MENUITEM_H

#include <string>

using namespace std;

class Menuitem {
private:
    string item;
public:
    void setItem(string);
    string getItem();
    Menuitem();
};

#endif // MENUITEM_H
