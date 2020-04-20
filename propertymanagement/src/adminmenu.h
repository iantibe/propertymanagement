#ifndef ADMINMENU_H
#define ADMINMENU_H

#include "menu.h"

class Adminmenu : Menu {
public:
    vector<Menuitem> buildAdminMenu();
    Adminmenu(string);
    void display() override;
};

#endif // ADMINMENU_H
