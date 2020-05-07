#ifndef TENANTUSER_H
#define TENANTUSER_H

#include "usertype.h"
#include "user.h"
#include "rentalunit.h"

class Tenantuser : public User {
private:
    Usertype type;
public:
    Usertype getUsertype();
    Tenantuser(int, string, string);
};

#endif // TENANTUSER_H
