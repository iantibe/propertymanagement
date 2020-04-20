#ifndef TENANT_H
#define TENANT_H

#include "Tenantuser.h"
#include "rentalunit.h"
#include "building.h"
class Tenant {
private:
    Tenantuser user;
public:
    Tenantuser getUser();
    void setUser(Tenantuser &);
    Tenant(Tenantuser &, Rentalunit &, Building &);
};

#endif // TENANT_H
