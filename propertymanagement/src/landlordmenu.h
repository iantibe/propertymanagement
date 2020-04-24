#ifndef LANDLORDMENU_H
#define LANDLORDMENU_H

#include "menu.h"
#include <constants.h>
#include "user.h"

class Landlordmenu : Menu {
public:
    vector<Menuitem> buildLandlordMenu();
    Landlordmenu(string, User);
    void display() override;

private:
    void displayViewMail();
    User currentUser;
    void displaySendMail();
};

#endif // LANDLORDMENU_H
