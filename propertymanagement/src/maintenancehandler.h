#ifndef MAINTENANCEHANDLER_H
#define MAINTENANCEHANDLER_H

#include "Databaseconnection.h"
#include <vector>
#include "maintenancerequest.h"

class Maintanancehandler : private Databaseconnection{
public:
    vector<Maintenancerequest> getCurrentRequests();
    void compleateRequest(Maintenancerequest &);
    void submitRequest(Maintenancerequest &);
     Maintanancehandler();
};

#endif // MAINTENANCEHANDLER_H
