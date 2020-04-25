#include "insertdata.h"
#include <ctime>
#include "errorhandler.h"
#include <iostream>


using namespace std;

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
