#include "adminmenu.h"
#include <iostream>
#include "constants.h"

using namespace std;

vector<Menuitem> Adminmenu::buildAdminMenu(){
    Menuitem item;
    vector<Menuitem> list;

    for(int j = 0; j< adminlist.size(); j++){
    list.push_back(item);

    }

    for(int k = 0; k < list.size(); k++){
        list[k].setItem(adminlist[k]);
    }
    return list;
}

Adminmenu::Adminmenu(string t) : Menu(t){

}

void Adminmenu::display(){

    vector<Menuitem> list = buildAdminMenu();

    bool exitFlag = false;

    int sel;

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
            exitFlag = true;
            break;

        }

    }







}
