#include "insertdata.h"
#include <ctime>
#include "errorhandler.h"
#include <iostream>


using namespace std;

void Insertdata::saveBuilding(Building  b){



    try {
        QSqlQuery query;
        query.prepare("insert into building (onsitelaundry, offstreetparking, multifamily , studio , onebed, twobed, threebed, rentcontrol, address) values(:onsitelaundry, :offstreetparking, :multifamily, :studio, :onebed, :twobed, :threebed, :rentcontrol, :address)");
        query.bindValue(":onsitelaundry",b.getOnSiteLaundry());
        query.bindValue(":offstreetparking",b.getOffStreetParking());
        query.bindValue(":multifamily",b.getMultiFamily());
        query.bindValue(":studio",b.getStudio());
        query.bindValue(":onebed",b.getOneBed());
        query.bindValue(":twobed", b.getTwoBed());
        query.bindValue(":threebed",b.getThreeBed());
        query.bindValue(":rentcontrol", b.getRentControlled());
        query.bindValue(":address", b.getAddress().c_str());
        query.exec();

        QSqlQuery test;

        test.prepare("select address from building");
        test.exec();
        test.next();
        qDebug() << test.value(0);


    } catch (exception e) {
        Errorhandler err;
        err.saveError("Error in saveBuildig method in insertdata.cpp");
        cout << "An error has occured. IT has been notified. Please try again" << endl;
    }
}

void Insertdata::saveRentalUnit(Rentalunit &){

}

void Insertdata::saveTenant(class Tenant & t){


}

void Insertdata::saveUser(User & u){


}

Insertdata::Insertdata(){

}


void Insertdata::saveError(string e){
  try{
        QSqlQuery sendata;
        time_t currentTime = time(0);

        sendata.prepare("INSERT INTO errortable (desc, time) VALUES (?, ?)");
        sendata.addBindValue(e.c_str());
        sendata.addBindValue(currentTime);
        sendata.exec();

} catch(exception e){
        Errorhandler error;
        error.saveError("saveError method in insertdata.cpp");
        cout << "An error has occured, and IT has been notified. Please try again.";
}


}


