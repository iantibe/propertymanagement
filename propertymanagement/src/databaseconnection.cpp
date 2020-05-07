#include "constants.h"
#include "Databaseconnection.h"
#include <iostream>
#include <QSqlError>


Databaseconnection::Databaseconnection(){

}

void Databaseconnection::openConnection(){

    const QString DRIVER(DATABASEDRIVER);

    if(!QSqlDatabase::isDriverAvailable(DRIVER)){
        cout << "Error, Driver is not available" ;
    }else{
        db = QSqlDatabase::addDatabase(DRIVER);

        //create database in memeory for inital testing. Then switch to disk database later
        //db.setDatabaseName(DATABASENAME);
        db.setDatabaseName(":memory:");

        if(!db.open()){
           cout << "ERROR: opening database";
        }else {
            //create databases
            createDatabase();
        }
    }
}

void Databaseconnection::closeConnection(){
    db.close();
}

bool Databaseconnection::checkConnectionOpen(){
    return db.isOpen();
}

Databaseconnection::~Databaseconnection(){
    db.close();
}

void Databaseconnection::createDatabase(){
    QSqlQuery query;
    query.exec("create table usertype (usertypeid INTEGER PRIMARY KEY, type TEXT)");
    query.exec("create table user (id INTEGER PRIMARY KEY, fname TEXT, lname TEXT, type INTEGER, uname TEXT, password TEXT, FOREIGN KEY (type) REFERENCES usertype(usertypeid))");
    query.exec("create table message (messageid INTEGER PRIMARY KEY, sendid INTEGER, receiveid INTEGER, subject TEXT, time INTEGER, message TEXT, read INTEGER, FOREIGN KEY (sendid) REFERENCES user (userid), FOREIGN KEY (receiveid) REFERENCES user (userid))");
    query.exec("create table errortable (errorid INTEGER PRIMARY KEY, desc TEXT, time INTEGER)");
    query.exec("create table building (buildingid INTEGER PRIMARY KEY, onsitelaundry INTEGER, offstreetparking INTEGER, multifamily INTEGER, studio INTEGER, onebed INTEGER, twobed INTEGER, threebed INTEGER, rentcontrol INTEGER, address TEXT)");
    query.exec("create table requesttype (requesttypeid INTEGER PRIMARY KEY, type TEXT)");
    query.exec("create table rentalunit (rentalunitid INTEGER PRIMARY KEY, buildingid INTEGER, userid INTEGER, unitnumber TEXT, FOREIGN KEY (buildingid) REFERENCES building (buildingid), FOREIGN KEY (userid) REFERENCES user (id))");
    query.exec("create table maintenancerequest (maintenancerequestid INTEGER PRIMARY KEY, rentalunitid INTEGER, isdone INTEGER, time INTEGER(8), desc TEXT, requesttypeid INTEGER, FOREIGN KEY(requesttypeid) REFERENCES requesttype(requesttypeid), FOREIGN KEY (rentalunitid) REFERENCES rentalunit (rentalunitid)) ");
    query.exec("create table rent (rentid INTEGER PRIMARY KEY, rentalunitid INTEGER, month TEXT, amount REAL, FOREIGN KEY (rentalunitid) REFERENCES rentalunit (rentalunitid))");

    //populate user type
    QSqlQuery insert;
    QVariant value1 = "Tenant";
    insert.prepare("Insert into usertype (type) VALUES (:value)");
    insert.bindValue(":value",value1);
    insert.exec();

    QVariant value2 = "Landlord";
    insert.prepare("Insert into usertype (type) VALUES (:value)");
    insert.bindValue(":value", value2);
    insert.exec();

    QVariant value3 = "Admin";
    insert.prepare("Insert into usertype (type) VALUES (:value)");
    insert.bindValue(":value", value3 );
    insert.exec();

    //populate users
    QSqlQuery insertuser;
    QVariant name1 = "adminuser";
    QVariant name2 = "tenantuser";
    QVariant name3 = "landlorduser";

    insertuser.prepare("INSERT INTO user (fname, lname, type, uname, password) VALUES (?, ?, ?, ?, ?)");

    insertuser.addBindValue("adminuser");
    insertuser.addBindValue("adminuser");
    insertuser.addBindValue(3);
    insertuser.addBindValue("adminuser");
    insertuser.addBindValue("adminuser");
    insertuser.exec();

    insertuser.addBindValue("tenantuser");
    insertuser.addBindValue("tenantuser");
    insertuser.addBindValue(1);
    insertuser.addBindValue("tenantuser");
    insertuser.addBindValue("tenantuser");
    insertuser.exec();

    insertuser.addBindValue("landlorduser");
    insertuser.addBindValue("landlorduser");
    insertuser.addBindValue(2);
    insertuser.addBindValue("landlorduser");
    insertuser.addBindValue("landlorduser");
    insertuser.exec();

    //populate request types
    QSqlQuery insertrequesttype;

    QVariant value10 = "Pluming";
    QVariant value11 = "Electrical";
    QVariant value12 =  "Finishes";
    QVariant value13 = "Lighting";
    QVariant value14 = "Flooring";
    QVariant value15 = "Other";

    insertrequesttype.prepare("insert into requesttype (type) values(:type)");
    insertrequesttype.bindValue(":type",value10 );
    insertrequesttype.exec();

    insertrequesttype.bindValue(":type", value11);
    insertrequesttype.exec();

    insertrequesttype.bindValue(":type", value12);
    insertrequesttype.exec();

    insertrequesttype.bindValue(":type", value13);
    insertrequesttype.exec();

    insertrequesttype.bindValue(":type", value14);
    insertrequesttype.exec();

    insertrequesttype.bindValue(":type", value15);
    insertrequesttype.exec();
}



