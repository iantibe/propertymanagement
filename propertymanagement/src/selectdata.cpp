#include "selectdata.h"
#include "errorhandler.h"
#include <iostream>

using namespace std;

User Selectdata::getUserbyScreenName(string nam){
   try{

    QSqlQuery getdata;

    getdata.prepare("select fname, lname, id from user where uname = :name");
    getdata.bindValue(":name", nam.c_str() );
    getdata.exec();

    getdata.next();

    QString lname = getdata.value(1).toString();
    QString fname = getdata.value(0).toString();

    User data(getdata.value(2).toULongLong(), fname.toStdString(),lname.toStdString());
    return data;

    }catch (exception e){
        Errorhandler error;
        error.saveError("getUserbyScreenNAme method in selectdata.cpp");
        cout << "An error has occured, and IT has been notified. Please try again.";
        User u(0,"","");
        return u;
    }

}

Selectdata::Selectdata(){

}

    int Selectdata::getUserType(User u){
    QSqlQuery getdata;

    try{
        getdata.prepare("select type from user where fname = :fname and lname = :lname");
        getdata.bindValue(":fname", u.getFname().c_str());
        getdata.bindValue(":lname", u.getLname().c_str());
        getdata.exec();
        getdata.next();

    int data = getdata.value(0).toULongLong();

    return data;

    } catch (exception e){
        Errorhandler error;
        error.saveError("getUserType method in selectdata.cpp");
        cout << "An error has occured, and IT has been notified. Please try again.";
        return 0;
    }
}

 User Selectdata::getUserById(int id){
     try{
        QSqlQuery query;
        query.prepare("select id, fname, lname from user where id = :id ");
        query.bindValue(":id" , id);
        query.exec();
        query.next();

        QString fname = query.value(1).toString();
        QString lname = query.value(2).toString();

    User u(query.value(0).toULongLong(), fname.toStdString() , lname.toStdString());

    return u;
     } catch (exception e){
         Errorhandler error;
         error.saveError("getUserById method in selectdata.cpp");
         cout << "An error has occured, and IT has been notified. Please try again.";
         User u(0,"","");
         return u;
     }
 }

vector<User> Selectdata::getUsers(){

    try {
    vector<User> list;
     QSqlQuery query;
     query.prepare("select id, fname, lname from user");
     query.exec();

     while(query.next()){
         QString fname = query.value(1).toString();
         QString lname = query.value(2).toString();
         User user(query.value(0).toULongLong(), fname.toStdString(), lname.toStdString());
         list.push_back(user);
     }

     return list;

    }catch (exception e){

        Errorhandler error;
        error.saveError("getusers method in selectdata.cpp");
        cout << "An error has occured, and IT has been notified. Please try again.";
        vector<User> errorreturn;
        return errorreturn;
    }
 }
