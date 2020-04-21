#include "selectdata.h"

User Selectdata::getUserbyScreenName(string nam){
    QSqlQuery getdata;

    getdata.prepare("select fname, lname, id from user where uname = :name");
    getdata.bindValue(":name", nam.c_str() );
    getdata.exec();

    getdata.next();

    QString lname = getdata.value(1).toString();
    QString fname = getdata.value(0).toString();

    User data(getdata.value(2).toULongLong(), fname.toStdString(),lname.toStdString());
    return data;

}

Selectdata::Selectdata(){

}

 int Selectdata::getUserType(User u){
    QSqlQuery getdata;

    getdata.prepare("select type from user where fname = :fname and lname = :lname");
    getdata.bindValue(":fname", u.getFname().c_str());
    getdata.bindValue(":lname", u.getLname().c_str());
    getdata.exec();
    getdata.next();

    int data = getdata.value(0).toULongLong();

    return data;

}
