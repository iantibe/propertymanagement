#include "tenantmenu.h"
#include <iostream>
#include "constants.h"
using namespace std;

vector<Menuitem> Tenantmenu::buildTenantMenu(){
    Menuitem item;
    vector<Menuitem> list;

    for(int j = 0; j< tenantlist.size(); j++){
    list.push_back(item);

    }

    for(int k = 0; k < list.size(); k++){
        list[k].setItem(tenantlist[k]);
    }
    return list;
}

Tenantmenu::Tenantmenu(string t): Menu(t){

}

void Tenantmenu::display(){
    bool exitFlag = false;
    int sel;
    vector<Menuitem> list = buildTenantMenu();

    while(!exitFlag){
        cout << getTitle() << endl << endl;
        drawmenu(list);
        sel = selection(list.size());

        switch (sel) {
        case 1:

            break;
        case 2:

            break;
        case 3:
            break;
        case 4:
            break;
        case 5:
            break;
        case 6:
            break;
        case 7:
            exitFlag = true;
            break;

        }

    }


}
