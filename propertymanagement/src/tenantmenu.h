#ifndef TENANTMENU_H
#define TENANTMENU_H

#include "menu.h"

class Tenantmenu : public Menu {
public:
    vector<Menuitem> buildTenantMenu();
    Tenantmenu(string);
    void display() override;
};

#endif // TENANTMENU_H
