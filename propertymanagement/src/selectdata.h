#ifndef SELECTDATA_H
#define SELECTDATA_H

#include "user.h"
#include "Databaseconnection.h"

class Selectdata : Databaseconnection{
public:
    User getUserbyName(string);
    Selectdata();
};




#endif // SELECTDATA_H
