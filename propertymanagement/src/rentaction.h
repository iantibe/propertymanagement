#ifndef RENTACTION_H
#define RENTACTION_H

#include "Databaseconnection.h"
#include "rent.h"
#include "Tenantuser.h"
#include <vector>

class Rentaction : private Databaseconnection {
public:
    void payRent(Rent);
    void viewRentDetail(Tenantuser); //for each tenant
    vector<Rent> viewUnpaidRents();
    Rentaction();
};

#endif // RENTACTION_H
