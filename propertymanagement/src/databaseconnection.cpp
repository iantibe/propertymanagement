#include "constants.h"
#include "Databaseconnection.h"
#include <iostream>

Databaseconnection::Databaseconnection(){

}

void Databaseconnection::openConnection(){

    const QString DRIVER(DATABASEDRIVER);

    if(!QSqlDatabase::isDriverAvailable(DRIVER)){
        cout << "Error, Driver is not available" ;
    }

    db = QSqlDatabase::addDatabase(DRIVER);

    //create database in memeory for inital testing. Then switch to disk database later
    //db.setDatabaseName(DATABASENAME);
    db.setDatabaseName(":memory:");

    if(!db.open()){
       cout << "ERROR: opening database";
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
