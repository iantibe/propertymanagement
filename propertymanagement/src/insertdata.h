#ifndef INSERTDATA_H
#define INSERTDATA_H

#include "Databaseconnection.h"
#include "user.h"
#include "building.h"
#include "rentalunit.h"
#include "tenant.h"
#include "error.h"

class Insertdata : Databaseconnection {
public:
    void saveBuilding(Building &);
    void saveRentalUnit(Rentalunit &);
    void saveTenant(class Tenant &);
    void saveUser(User &);
    void saveError(string);
    Insertdata();
};

#endif // INSERTDATA_H
