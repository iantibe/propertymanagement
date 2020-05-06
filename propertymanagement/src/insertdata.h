#ifndef INSERTDATA_H
#define INSERTDATA_H

#include "Databaseconnection.h"
#include "user.h"
#include "building.h"
#include "rentalunit.h"
#include "tenant.h"
#include "errorhandler.h"
#include "rent.h"


class Insertdata : Databaseconnection {
public:
    void saveBuilding(Building );
    void saveRentalUnit(Rentalunit &);
    void saveTenant(class Tenant &);
    void saveUser(User &, string, string);
    void saveError(string);
    void saveRent(Rent &);


    Insertdata();
};

#endif // INSERTDATA_H
