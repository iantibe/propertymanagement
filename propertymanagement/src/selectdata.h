#ifndef SELECTDATA_H
#define SELECTDATA_H

#include "user.h"
#include "Databaseconnection.h"
#include "building.h"
#include "rent.h"
#include "Tenantuser.h"

class Selectdata : Databaseconnection{
public:
    User getUserbyScreenName(string);
    int getUserType(User);
    Selectdata();
    User getUserById(int);
    vector <User> getUsers();
    vector <Building> getListOfBuildings();
    int getUserId(string, string);
    vector <Rent> getRentsForTenant(Tenantuser);
    int getRentalunitIdbyTenant(Tenantuser);
};




#endif // SELECTDATA_H
