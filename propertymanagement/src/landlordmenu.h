#ifndef LANDLORDMENU_H
#define LANDLORDMENU_H

#include "menu.h"

class Landlordmenu : Menu {
public:
    vector<Menuitem> buildLandlordMenu();
    Landlordmenu(string);
    void display() override;
};

#endif // LANDLORDMENU_H
