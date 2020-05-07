#include "adminmenu.h"
#include <iostream>
#include "constants.h"
#include "errorhandler.h"
#include <ctime>

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
            displayErrorReport();
            break;
        case 2:
            displayUserToReceiveLandlordMail();
            break;
        case 3:
            exitFlag = true;
            break;
        default:
            cout << "Please enter a valid menuitem" << endl;
            break;

        }

    }

}

void Adminmenu::displayErrorReport(){
    Errorhandler errorhandler;
    vector<Error> list = errorhandler.getErrors();
    cout << "Current Errors: " << endl;

    for(int i = 0; i < list.size(); i++){
        cout << "------------------------------------" << endl;
        cout << "Error Time: " << list.at(i).getTime() << endl;
        cout << "Error Description: " << list.at(i).getDesc() << endl;
        cout << "------------------------------------" << endl;
    }
    cout << "End of list" << endl;
}

void Adminmenu::displayUserToReceiveLandlordMail(){
    cout << "The landlord user: " << landlordMailUser << " will receive all mail from tenants" << endl;
}
