#ifndef SELECTDATA_H
#define SELECTDATA_H

#include "user.h"
#include "Databaseconnection.h"

class Selectdata : Databaseconnection{
public:
    User getUserbyScreenName(string);
    int getUserType(User);
    Selectdata();

};




#endif // SELECTDATA_H
