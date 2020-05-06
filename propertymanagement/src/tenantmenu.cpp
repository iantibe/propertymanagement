#include "tenantmenu.h"
#include <iostream>
#include "constants.h"
#include "message.h"
#include "selectdata.h"
#include "messagehandler.h"
#include "Tenantuser.h"
#include "rent.h"
#include "insertdata.h"
#include "maintenancehandler.h"
#include "tenant.h"

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

Tenantmenu::Tenantmenu(string t, User u): Menu(t), currentUser(u){

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
            displayPayRent();
            break;
        case 2:
            viewRentTransactions();
            break;
        case 3:
            sendMaintananceRequest();
            break;
        case 4:
            displayOpenMaintanceRequests();
            break;
        case 5:
            //send mail
            displaySendMail();
            break;
        case 6:
            displayViewMail();
            break;
        case 7:
            exitFlag = true;
            break;

        }

    }


}

void Tenantmenu::displaySendMail(){
    string subject;
    string message;
    cout << "Send mail to Landlord" << endl;
    cout << "Message will automatically be sent to Landlord" << endl;
    cout << "Enter subject: ";
    cin >> subject;
    cout << "Enter message: ";
    cin >> message;
    Messagehandler messagehandler;
    Selectdata instance;
    time_t nowtime = time(0);

    Message messagetoSend(instance.getUserbyScreenName(landlordMailUser),currentUser,nowtime);
    messagetoSend.setMessage(message);
    messagetoSend.setSubject(subject);

    messagehandler.sendMessage(messagetoSend);
    cout << "Message sent!" << endl;

}

void Tenantmenu::displayViewMail(){

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

void Tenantmenu::displayPayRent(){
    Insertdata insert;
    float rentAmt;
    int month;
    cout << "Pay Rent: " << currentUser.getFname() << " " << currentUser.getLname();

    cout << "Enter month id: " << endl;

    cout << "--------------------" << endl;
    for(int i = 0; i < monthlist.size(); i++){
        cout << i+1 << ". " <<monthlist[i] << endl;
    }
    cout << "--------------------" << endl;
    cin >> month;
    cout << "Enter Rent amount" << endl;
    cin >> rentAmt;

//access month month-1

    Tenantuser tenantuser(currentUser.getUserid(),currentUser.getFname(),currentUser.getLname());
    Rent rent(tenantuser, rentAmt,monthlist[month-1]);
    insert.saveRent(rent);
    cout << "Rent saved!" << endl;

}

void Tenantmenu::viewRentTransactions(){
    Selectdata selectdata;
    vector<Rent> list;
    Tenantuser tenantuser(currentUser.getUserid(),currentUser.getFname(), currentUser.getLname());
   list = selectdata.getRentsForTenant(tenantuser);

    cout << "Rents paid:" << endl;
    cout << "-----------------------------------------" << endl;
    for(int i = 0; i < list.size(); i++){
        cout << "Month: " << list.at(i).getMonth() << endl;
        cout << "Amount: $" << list.at(i).getRent() << endl;
        cout << "-------------------------------------" << endl;
    }
    cout << "End of list" << endl;
}


void Tenantmenu::sendMaintananceRequest(){
    Maintanancehandler mr;
    int selection;
    int maintainancetypeid;
    string problem;
    time_t now = time(0);
    Selectdata selectdata;
    vector<string> list = selectdata.getMaintenanceRequestTypes();
    cout << "Send maintance request" << endl;


    cout << "Select request type" << endl;
    cout << "---------------------------" << endl;
    for(int i = 0; i < list.size(); i++){
        cout << i+1 <<" " << list.at(i) << endl;
    }
    cout << "---------------------------" << endl;
    cin >> selection;

    maintainancetypeid = selectdata.getMaintenanceRequestTypeId(list.at(selection -1));

    cout << "What is the problem: " << endl;
    cin >> problem;


    Tenantuser user(currentUser.getUserid(),currentUser.getFname(),currentUser.getLname());
    int rentalunitid = selectdata.getRentalunitIdbyTenant(user);
    Rentalunit unit("","",false,false,false,0,0,0,0,false);

    class Tenant tenant(user,unit);

    Maintenancerequest request(tenant,now, maintainancetypeid, problem);

    mr.submitRequest(request, rentalunitid);

}

void Tenantmenu::displayOpenMaintanceRequests(){
   Maintanancehandler mh;
   Selectdata selectdata;
   Tenantuser tenantuser(currentUser.getUserid(),currentUser.getFname(),currentUser.getLname());
   vector<Maintenancerequest> unfinshed;
   vector<Maintenancerequest> finished;
   unfinshed = mh.getTenantUnfinishedRequests(tenantuser);
   finished = mh.getTenantFinishedRequests(tenantuser);

    cout << "Current OPEN Maintance Requests are:" <<  endl;
    cout << "--------------" << endl;
    for(int i = 0; i < unfinshed.size(); i++){
        cout << "---------------" << endl;
        cout << "Time Submitted: " << unfinshed.at(i).getTime() << endl;
        cout << "Issue Type: " << mh.getMaintenanceTypeById(unfinshed.at(i).getRequestType()) << endl;
        cout << "Description: " << unfinshed.at(i).getDescription() << endl;
        cout << "---------------" << endl;
    }
    cout << "--------------" << endl;

    cout << "Current CLOSED maintanance requests are: "<< endl;
   cout << "----------------" << endl;
    for(int j = 0; j < finished.size(); j++){
        cout << "----------------------------" << endl;
        cout << "Time Submitted: " << finished.at(j).getTime() << endl;
        cout << "Issue Type: " << mh.getMaintenanceTypeById(finished.at(j).getRequestType()) << endl;
        cout << "Description: " << finished.at(j).getDescription() << endl;
        cout << "----------------------------" << endl;
    }
    cout << "---------------" << endl;
}
