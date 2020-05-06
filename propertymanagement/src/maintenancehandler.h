#ifndef MAINTENANCEHANDLER_H
#define MAINTENANCEHANDLER_H

#include "Databaseconnection.h"
#include <vector>
#include "maintenancerequest.h"

class Maintanancehandler : private Databaseconnection{

public:
    vector<Maintenancerequest> getCurrentRequests();
    void compleateRequest(Maintenancerequest &);
    void submitRequest(Maintenancerequest &, int rentalunitid);
     Maintanancehandler();
     vector<Maintenancerequest> getTenantUnfinishedRequests(Tenantuser &);
     vector<Maintenancerequest> getTenantFinishedRequests(Tenantuser &);
     string getMaintenanceTypeById(int);
};

#endif // MAINTENANCEHANDLER_H
