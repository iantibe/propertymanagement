#ifndef MAINTENANCEREQUEST_H
#define MAINTENANCEREQUEST_H

#include "tenant.h"
#include <ctime>
#include "constants.h"
#include <string>

class Maintenancerequest{
private:
    class Tenant tenant;
    time_t time;
    int requesttype;
    string description;
    int maintenancerequestid;
public:
    class Tenant getTenant();
    time_t getTime();
    int getRequestType();
    string getDescription();
    void setTenant(class Tenant &);
    void setTime(time_t);
    void setRequestType(int);
    void setDescription(string);
    Maintenancerequest(class Tenant, time_t, int, string);
    void setMaintenancerequestid(int);
    int getMaintenancerequestid();
};

#endif // MAINTENANCEREQUEST_H
