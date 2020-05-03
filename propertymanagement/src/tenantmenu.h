#ifndef TENANTMENU_H
#define TENANTMENU_H
#include "user.h"

#include "menu.h"

class Tenantmenu : public Menu {
public:
    vector<Menuitem> buildTenantMenu();
    Tenantmenu(string, User);
    void display() override;
    User getUser();
    void setUser(User);

private:
    void displaySendMail();
    User currentUser;
    void displayViewMail();
    void displayPayRent();
    void viewRentTransactions();
};

#endif // TENANTMENU_H
