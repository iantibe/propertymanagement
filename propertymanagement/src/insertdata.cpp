#include "insertdata.h"
#include <ctime>

void Insertdata::saveBuilding(Building &){

}

void Insertdata::saveRentalUnit(Rentalunit &){

}

void Insertdata::saveTenant(class Tenant &){

}

void Insertdata::saveUser(User &){

}

Insertdata::Insertdata(){

}

void Insertdata::saveError(string e){
    QSqlQuery sendata;
    time_t currentTime = time(0);

    sendata.prepare("INSERT INTO errortable (desc, time) VALUES (?, ?)");
    sendata.addBindValue(e.c_str());
    sendata.addBindValue(currentTime);

    sendata.exec();



}
