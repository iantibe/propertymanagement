#include "messagehandler.h"
#include "Databaseconnection.h"
#include <iostream>
#include "errorhandler.h"
#include <QSqlError>
#include <QSqlDatabase>
#include <QSqlQuery>
#include "selectdata.h"

using namespace std;

void Messagehandler::sendMessage(Message & m){

    try {
        //added db.open to prevent error
        db.open();
        QSqlQuery sendmail;
        sendmail.prepare("INSERT INTO message (sendid, receiveid, subject, time , message, read) VALUES (:sendid, :receiveid, :subject, :time, :message, :read)");

        sendmail.bindValue(":sendid",m.getSender().getUserid());
        sendmail.bindValue(":receiveid",m.getReceiver().getUserid());
        sendmail.bindValue(":subject", m.getSubject().c_str());
        sendmail.bindValue(":time", m.getTimeDateSent());
        sendmail.bindValue(":message", m.getMessage().c_str());
        if(m.getIsRead() == true){
        sendmail.bindValue(":read", 1);
        }else{
        sendmail.bindValue(":read", 0);
        }
        sendmail.exec();


    } catch (exception e) {

        cout << "An error occured while sending your mail. IT has been notified. Please try again." << endl;

    }


}

vector<Message> Messagehandler::getUnreadMessages(User & u){
        QSqlQuery query;
        Selectdata selectdata;
        vector<Message> list;
        query.prepare("select messageid, sendid, receiveid, subject, time, message, read from message where read = 0 and sendid = :send");
        query.bindValue(":send" , u.getUserid());
        query.exec();



        while(query.next()){
            User receive = selectdata.getUserById(query.value(2).toULongLong());
            Message m(u,receive,query.value(4).toULongLong());
            m.setIsRead(query.value(6).toULongLong());
            QString message = query.value(5).toString();
            m.setMessage(message.toStdString());
            QString subject = query.value(3).toString();
            m.setSubject(subject.toStdString());
            m.setMessageId(query.value(0).toULongLong());

            list.push_back(m);
        }

        return list;

}

void Messagehandler::deleteMessage(Message & m){

}

vector<Message> Messagehandler::listReadMessages(User & u){
    QSqlQuery query;
    Selectdata selectdata;
    vector<Message> list;
    query.prepare("select messageid, sendid, receiveid, subject, time, message, read from message where read = 1 and sendid = :send");
    query.bindValue(":send" , u.getUserid());
    query.exec();



    while(query.next()){
        User receive = selectdata.getUserById(query.value(2).toULongLong());
        Message m(u,receive,query.value(4).toULongLong());
        m.setIsRead(query.value(6).toULongLong());
        QString message = query.value(5).toString();
        m.setMessage(message.toStdString());
        QString subject = query.value(3).toString();
        m.setSubject(subject.toStdString());
        m.setMessageId(query.value(0).toULongLong());

        list.push_back(m);
    }

    return list;
}

void Messagehandler::updateReadStatus(int id) {
    QSqlQuery query;
    query.prepare("update message set read = 1 where messageid = :messageid");
    query.bindValue(":messageid", id);
    query.exec();
}
