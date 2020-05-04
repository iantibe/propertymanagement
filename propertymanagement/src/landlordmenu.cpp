#include "landlordmenu.h"
#include <iostream>
#include "message.h"
#include "messagehandler.h"
#include "selectdata.h"
#include "building.h"
#include "insertdata.h"

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

Landlordmenu::Landlordmenu(string t, User u): Menu(t), currentUser(u){


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
            addTenant();
            break;
        case 2:

            break;
        case 3:
            addBuilding();
            break;
        case 4:
            break;
        case 5:
            break;
        case 6:
            displayViewMail();
            break;
        case 7:
            displaySendMail();
            break;
        case 8:
            displayAllRents();
            break;
        case 9:
            exitFlag = true;
            break;

        }
        }
}

void Landlordmenu::displayViewMail(){
    Messagehandler messagehandler;

    vector<Message> list = messagehandler.getUnreadMessages(currentUser);


        cout << "UNREAD MESSAGES" << endl;
        for(int i = 0; i < list.size(); i++){
            cout << "--------------------------------------------------" << endl;
            cout << "Message id: " << list.at(i).getMessageId() << endl;
            cout << "Received from: " << list.at(i).getReceiver().getFname() << " " << list.at(i).getReceiver().getLname() << endl;
            cout << "Subject: " << list.at(i).getSubject() << endl;
            cout << "Time: " << list.at(i).getTimeDateSent() << endl;
            cout << "Message: " << list.at(i).getMessage() << endl << endl<< endl ;
            cout << "--------------------------------------------------" << endl;
            messagehandler.updateReadStatus(list.at(i).getMessageId());

        }

        cout << "READ MESSAGES" << endl;
        vector<Message> readlist = messagehandler.listReadMessages(currentUser);

        for(int i = 0; i < readlist.size(); i++){
            cout << "--------------------------------------------------" << endl;
            cout << "Message id: " << readlist.at(i).getMessageId() << endl;
            cout << "Received from: " << readlist.at(i).getReceiver().getFname() << " " << readlist.at(i).getReceiver().getLname() << endl;
            cout << "Subject: " << readlist.at(i).getSubject() << endl;
            cout << "Time: " << readlist.at(i).getTimeDateSent() << endl;
            cout << "Message: " << readlist.at(i).getMessage() << endl << endl<< endl ;
            cout << "--------------------------------------------------" << endl;

        }


}

void Landlordmenu::displaySendMail(){
    Messagehandler messagehandler;
    Selectdata instance;
    int sel;
    time_t nowtime = time(0);
    vector<User> userList;
    string subject;
    string message;
    cout << "Send mail to any user" << endl;
    cout << "Enter subject: ";
    cin >> subject;
    cout << "Enter message: ";
    cin >> message;

    userList = instance.getUsers();

    for(int i = 0; i < userList.size(); i++){
        cout << i+1 << "   " << userList.at(i).getFname() << " " << userList.at(i).getLname() << endl;
    }

    sel = selection(userList.size());

    Message messagetoSend(userList.at(sel-1),currentUser,nowtime);
    messagetoSend.setMessage(message);
    messagetoSend.setSubject(subject);


    messagehandler.sendMessage(messagetoSend);
    cout << "Message sent!" << endl;
}

void Landlordmenu::addBuilding(){
    Insertdata insert;
    int  onSiteLaundry;
    int rentControlled;
    int offStreetParking;
    int multiFamily;

    char onsitelaundry;
    char rentcontroled;
    char offstreetparking;
    char multifamily;

    string address;
    int oneBed;
    int twoBed;
    int threeBed;
    int studio;


    cout << "Add Tenant" << endl;
    cout << "What is the address?" << endl;
    cin >> address;
    cout << "How many studio apartments?" << endl;
    cin >> studio;
    cout << "How many one bed room apartments?" << endl;
    cin >> oneBed;
    cout << "How many two bed room apartments?" << endl;
    cin >> twoBed;
    cout << "How many three bed room apartments?" << endl;
    cin >> threeBed;
    cout << "Is it rent controlled? Enter y for yes and n for no" << endl;
    cin >> rentcontroled;

    if (rentcontroled == 'y' || rentcontroled == 'Y'){
       rentControlled = 1;
    }else {
        rentControlled = 0;
    }
    cout << "Is Building multi family? Enter y for yes and n for no" << endl;
    cin >> multifamily;

    if(multifamily == 'y' || multifamily == 'n'){
        multiFamily = 1;
    }else{
        multiFamily = 0;
    }

    cout << "Does building have on site laundry? Enter y for yes and n for no" << endl;
    cin >> onsitelaundry;

    if(onsitelaundry == 'y' || onsitelaundry == 'Y'){
        onSiteLaundry = 1;
    }else {
        onSiteLaundry = 0;
    }

    cout << "Does the building have off street parking? Enter y for yes and n for on" << endl;
    cin >> offstreetparking;

    if (offstreetparking == 'y' || offstreetparking == 'Y'){
        offStreetParking = 1;
    }else {
        offStreetParking =0;
    }

    Building building(address, onSiteLaundry,offStreetParking,multiFamily,studio,oneBed,twoBed,threeBed,rentControlled);

    insert.saveBuilding(building);

    cout << "Building Saved!!" << endl;

}

void Landlordmenu::addTenant(){
    Insertdata insert;
    string fnam;
    string lnam;
    string screenname;
    string password;
    string unit;

    Insertdata insertdata;
    Selectdata selectdata;
    vector<Building> list;
    int vectorIndexOfBuilding;

    cout << "Add tenant" << endl;
    cout << "Tenant firstname: " << endl;
    cin >> fnam;
    cout << "Tenant lastname: " <<endl;
    cin >> lnam;
    cout << "Tenant user name:" << endl;
    cin >> screenname;
    cout << "Tenant password: " << endl;
    cin >> password;

    cout << "Which building to assign tenant: " << endl;
    list = selectdata.getListOfBuildings();

    cout << "-----------------------------------" << endl;
    for(int i = 0; i < list.size(); i++){
     cout << i+1 << ". " <<  list.at(i).getAddress() << endl;
    }

    cout << "Enter Building number: " << endl;
    cin >> vectorIndexOfBuilding;

    cout << "Which unit in " << list.at(vectorIndexOfBuilding-1).getAddress() << " to assign to Tenant" << endl;
    cin >> unit;

    //add user to database so we can get an userid from user table
    User newUser(0,fnam,lnam);
    insertdata.saveUser(newUser,screenname,password);
    int userId = selectdata.getUserId(newUser.getFname(),newUser.getLname());
    cout << "userid of new user is: " << userId << endl;
    newUser.setUserid(userId);

    //test


    // how to address building :list.at(vectorIndexOfBuilding -1);

    Rentalunit rentalunit(unit,list.at(vectorIndexOfBuilding -1));

    Tenantuser tenantuser(newUser.getUserid(),newUser.getFname(),newUser.getLname());

    class Tenant tenant(tenantuser,rentalunit);

    insert.saveTenant(tenant);
    cout << "Tenant Saved!" << endl;

}

void Landlordmenu::displayAllRents(){
    vector<Tenantuser> listoftenantusers;
    Selectdata selectdata;
    listoftenantusers = selectdata.getAllTenantUsers();
    vector<Rent> listofrents;

    for (int p  = 0; p < listoftenantusers.size(); p++){
        cout << "-------------------------------------------" << endl;
        cout << "Rent for: " << listoftenantusers[p].getFname() << " " << listoftenantusers[p].getLname() << endl;
        listofrents.clear();
        listofrents = selectdata.getRentsForTenant(listoftenantusers[p]);

        for(int j = 0; j < listofrents.size(); j++){
            cout << "Month: " << listofrents[j].getMonth() << endl;
            cout << "Rent: "  <<listofrents[j].getRent() << endl;

        }
        cout << "------------------------------------------" << endl;
    }

}
