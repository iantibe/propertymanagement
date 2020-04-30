#ifndef TENANT_H
#define TENANT_H

#include "Tenantuser.h"
#include "rentalunit.h"
#include "building.h"
class Tenant {
private:
    Tenantuser user;
    Rentalunit unit;
public:
    Tenantuser getUser();
    void setUser(Tenantuser &);
    void setRentalunit(Rentalunit &);
    Rentalunit getRentalunit();

    Tenant(Tenantuser &, Rentalunit );
};

#endif // TENANT_H
