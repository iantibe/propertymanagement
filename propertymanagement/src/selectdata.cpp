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

vector<Building> Selectdata::getListOfBuildings(){
    try{
    QSqlQuery query;
    vector<Building> list;

    query.prepare("select buildingid, onsitelaundry, offstreetparking, multifamily, studio, onebed, twobed, threebed , rentcontrol, address from building");
    query.exec();

    while (query.next()){
    QString add = query.value(9).toString();
    Building building(add.toStdString(),query.value(1).toULongLong(),query.value(2).toLongLong(),query.value(3).toLongLong(),query.value(4).toULongLong(),query.value(5).toULongLong(),query.value(6).toULongLong(),query.value(7).toULongLong(), query.value(8).toULongLong());
    building.setBuildingId(query.value(0).toULongLong());
    list.push_back(building);
    }

    return list;

    } catch (exception e){
        Errorhandler err;
        cout << "An Error has occured. IT has been notified. Please try again" << endl;
        err.saveError("Error in getlistofbuilding in selectdata.cpp");
        vector<Building> errlist;
        return errlist;
    }

}

int Selectdata::getUserId(string fnam, string lnam){
    QSqlQuery query;
    query.prepare("select id from user where fname = :fname and lname = :lname");
    query.bindValue(":fname" , fnam.c_str());
    query.bindValue(":lname" , lnam.c_str());
    query.exec();

    return query.value(0).toULongLong();

}
