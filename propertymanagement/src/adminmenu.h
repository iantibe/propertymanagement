#ifndef ADMINMENU_H
#define ADMINMENU_H

#include "menu.h"

class Adminmenu : Menu {
public:

    Adminmenu(string);
    void display() override;
private:
    vector<Menuitem> buildAdminMenu();
    void displayErrorReport();
};

#endif // ADMINMENU_H
