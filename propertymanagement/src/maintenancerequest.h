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
    Requesttype request;
    string description;
public:
    class Tenant getTenant();
    time_t getTime();
    Requesttype getRequestType();
    string getDescription();
    void setTenant(class Tenant &);
    void setTime(time_t);
    void setRequestType(Requesttype);
    void setDescription(string);
    Maintenancerequest(class Tenant, time_t, Requesttype, string);
};

#endif // MAINTENANCEREQUEST_H
