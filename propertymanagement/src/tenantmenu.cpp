#include "tenantmenu.h"
#include <iostream>
#include "constants.h"
#include "message.h"
#include "selectdata.h"
#include "messagehandler.h"

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

            break;
        case 2:

            break;
        case 3:
            break;
        case 4:
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

    if(list.size() == 0){
        cout << "No messages to display" <<  endl;

    }else{

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



}
