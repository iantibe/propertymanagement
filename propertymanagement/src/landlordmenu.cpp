#include "landlordmenu.h"
#include <iostream>

using namespace std;

vector<Menuitem> Landlordmenu::buildLandlordMenu(){
    Menuitem item;
    vector<Menuitem> list;

    for(int j = 0; j< landlordlist.size(); j++){
    list.push_back(item);

    }

    for(int k = 0; k < list.size(); k++){
        list[k].setItem(landlordlist[k]);
    }
    return list;
}

Landlordmenu::Landlordmenu(string t): Menu(t){


}

void Landlordmenu::display(){
    bool exitFlag = false;
    int sel = 0;

    vector<Menuitem> list = buildLandlordMenu();

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

            break;
        case 8:
            break;
        case 9:
            exitFlag = true;
            break;

        }
        }
}
