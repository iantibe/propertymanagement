#ifndef RENT_H
#define RENT_H

#include "tenant.h"

class Rent {
private:
    Tenantuser user;
    float rent;
    string month;
public:
    Rent(Tenantuser &, float rent);
    void setTenant(Tenantuser &);
    void setRent(float);
    Tenantuser getTenant();
    float getRent();
    void setMonth(string);
    string getMonth();
};

#endif // RENT_H
