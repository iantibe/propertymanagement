#ifndef SELECTDATA_H
#define SELECTDATA_H

#include "user.h"
#include "Databaseconnection.h"
#include "building.h"

class Selectdata : Databaseconnection{
public:
    User getUserbyScreenName(string);
    int getUserType(User);
    Selectdata();
    User getUserById(int);
    vector <User> getUsers();
    vector <Building> getListOfBuildings();
    int getUserId(string, string);

};




#endif // SELECTDATA_H
