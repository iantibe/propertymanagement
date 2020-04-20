#ifndef INSERTDATA_H
#define INSERTDATA_H

#include "Databaseconnection.h"
#include "user.h"
#include "building.h"
#include "rentalunit.h"
#include "tenant.h"

class Insertdata : Databaseconnection {
    void saveBuilding(Building &);
    void saveRentalUnit(Rentalunit &);
    void saveTenant(class Tenant &);
    void saveUser(User &);
    Insertdata();
};

#endif // INSERTDATA_H
