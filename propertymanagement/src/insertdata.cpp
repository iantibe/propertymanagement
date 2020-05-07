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

    } catch (exception e) {
        Errorhandler err;
        err.saveError("Error in saveBuildig method in insertdata.cpp");
        cout << "An error has occured. IT has been notified. Please try again" << endl;
    }
}

void Insertdata::saveTenant(class Tenant & t){
    QSqlQuery query;
    query.prepare("insert into rentalunit (buildingid, userid, unitnumber) values(:buildingid, :userid, :unitnumber)");
    query.bindValue(":buildingid",t.getRentalunit().getBuilding().getBuildingId());
    query.bindValue(":userid",t.getUser().getUserid());
    query.bindValue(":unitnumber",t.getRentalunit().getUnitnumber().c_str());
    query.exec();
   }

void Insertdata::saveUser(User & u, string uname, string pw){
    QSqlQuery insertuser;
    insertuser.prepare("INSERT INTO user (fname, lname, type, uname, password) VALUES (?, ?, ?, ?, ?)");
    insertuser.addBindValue(u.getFname().c_str());
    insertuser.addBindValue(u.getLname().c_str());
    insertuser.addBindValue(1);
    //user type for tenant is 1
    insertuser.addBindValue(uname.c_str());
    insertuser.addBindValue(pw.c_str());
    insertuser.exec();

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

void Insertdata::saveRent(Rent & rent){
    int unitid;
    QSqlQuery getrentalunit;
    getrentalunit.prepare("select rentalunitid from rentalunit where userid = :userid");
    getrentalunit.bindValue(":userid", rent.getTenant().getUserid());
    getrentalunit.exec();
    getrentalunit.next();
    unitid = getrentalunit.value(0).toULongLong();

    QSqlQuery query;
    query.prepare("insert into rent (rentalunitid, month, amount) values(:rentalunitid, :month, :amount)");
    query.bindValue(":rentalunitid", unitid);
    query.bindValue(":month",rent.getMonth().c_str());
    query.bindValue(":amount",rent.getRent());
    query.exec();

}


