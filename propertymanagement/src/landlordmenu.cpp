#include "landlordmenu.h"
#include <iostream>
#include "message.h"
#include "messagehandler.h"
#include "selectdata.h"


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
            displayViewMail();
            break;
        case 7:
            displaySendMail();
            break;
        case 8:
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
