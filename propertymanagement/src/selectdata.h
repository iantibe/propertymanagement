#ifndef SELECTDATA_H
#define SELECTDATA_H

#include "user.h"
#include "Databaseconnection.h"

class Selectdata : Databaseconnection{
public:
    User getUserbyScreenName(string);
    int getUserType(User);
    Selectdata();
    User getUserById(int);
    vector <User> getUsers();

};




#endif // SELECTDATA_H
